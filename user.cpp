#include "user.h"

User::User() = default;

void User::serialize() const {
    QString str = m_name + ";" + QString::number(m_age) + "&" + m_date.toString("yyyy-MM-dd") + "*";

    QFile outFile("/home/sandra/tasks/Serialization/file.txt");
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file for writing:" << outFile.errorString();
        return;
    }
    QTextStream out(&outFile);
    out << str << "\n";
    outFile.close();
}

void User::deserialize()  {
    QFile inFile("/home/sandra/tasks/Serialization/file.txt");
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file for writing:" << inFile.errorString();
        return;
    }
    QTextStream in(&inFile);
    QString str;
    in >> str;
    QString tmp;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ';') {
            m_name = tmp;
            tmp = "";
            continue;
        }
        else if (str[i] == '&') {
            bool ok;
            m_age = tmp.toInt(&ok);
            tmp = "";
            continue;
        }
        else if (str[i] == '*') {
            m_date = QDate::fromString(tmp, "yyyy-MM-dd");
            tmp = "";
            continue;
        }
        tmp += str[i];
    }

    inFile.close();
}

void User::setName(const QString& name) {
    m_name = name;
}

void User::setAge(int age) {
    m_age = age;
}

void User::setBirthDate(const QDate& date) {
    m_date = date;
}

QString User::getName() const {
    return m_name;
}

int User::getAge() const {
    return m_age;
}

QString User::getBirthDate() const {
    return m_date.toString("yyyy-MM-dd");
}
