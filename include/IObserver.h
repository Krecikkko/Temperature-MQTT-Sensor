#ifndef IOBSERVER_H
#define IOBSERVER_H

template <typename T>
class IObserver {
public:
    virtual void onUpdate(const T& value) = 0;
    virtual ~IObserver() {};
};

#endif // IOBSERVER_H