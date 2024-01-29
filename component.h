#ifndef COMPONENT_H
#define COMPONENT_H
#include <QList>
#include <QStringList>

class Component
{
protected:
    Component* parent;
public:
    explicit Component(Component* parent = nullptr);
    Component* getParent(){return parent;}
    virtual void add(Component* child){}
    virtual void remove(int index){}
    virtual Component* get(int index){return nullptr;}
    virtual int getChildrenCount(){return 0;}
    virtual bool isComposite(){return false;}
    virtual float getPrice() = 0;
    virtual QStringList getList() = 0;
    virtual ~Component() {}
};

class Leaf : public Component
{
public:
    float price;
    QString name;
    Leaf(float price, QString name, Component* parent);
    float getPrice() override;
    QStringList getList() override;
    ~Leaf() override{}

};

class Composite : public Component
{
private:
    QList<Component*> children;
public:
    QString name;
    Composite(QString name, Component* parent);
    void add(Component* child) override;
    void remove(int index) override;
    Component* get(int index) override;
    int getChildrenCount() override;
    bool isComposite() override;
    float getPrice() override;
    QStringList getList() override;
    ~Composite() override;
};

#endif // COMPONENT_H
