#ifndef SERIALIZE_DESERIALIZE_H
#define SERIALIZE_DESERIALIZE_H

class serialize_deserialize
{
public:
    virtual void serialize() const = 0;
    virtual void deserialize() = 0;
};

#endif // SERIALIZE_DESERIALIZE_H
