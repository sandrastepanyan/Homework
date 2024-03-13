#ifndef USER_H
#define USER_H

#include <QDate>
#include <QFile>
#include "serialize_deserialize.h"

class User : public serialize_deserialize
{
public:
    User();
    void serialize() const override;
    void deserialize() override;

    void setName(const QString& name);
    void setAge(int age);
    void setBirthDate(const QDate& date);

    QString getName() const;
    int getAge() const;
    QString getBirthDate() const;

private:
    QString m_name;
    int m_age;
    QDate m_date;
};

#endif // USER_H
