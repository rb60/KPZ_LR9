#include "component.h"
#include <QRegularExpression>

Component::Component(Component* parent)
{
    this->parent = parent;
}

Leaf::Leaf(float price, QString name,  Component *parent) : Component(parent)
{
    this->price = price;
    this->name = name;
}

float Leaf::getPrice()
{
    return price;
}

QStringList Leaf::getList()
{
    return QStringList(name + " | price: " + QString::number(price) + " Đ");
}

Composite::Composite(QString name, Component *parent) : Component(parent)
{
    this->name = name;
}

void Composite::add(Component* child)
{
    children.append(child);
}

void Composite::remove(int index)
{
    if(index < children.size())
    {
        children.removeAt(index);
    }
}

Component *Composite::get(int index)
{
    if(index < children.size())
    {
        return children[index];
    }
    return nullptr;
}

int Composite::getChildrenCount()
{
    return children.size();
}

bool Composite::isComposite()
{
    return true;
}

float Composite::getPrice()
{
    float result = 0;
    for(int i = 0; i < children.size(); i++)
    {
        result += children[i]->getPrice();
    }
    return result;
}

QStringList Composite::getList()
{
    QStringList result(name + " | price: " + QString::number(getPrice()) + " Đ");
    QStringList childList;
    for(int i = 0; i < children.size(); i++)
    {
        childList = children[i]->getList();
        childList.replaceInStrings(QRegularExpression("^"), "    ");
        result.append(childList);
    }
    return result;
}

Composite::~Composite()
{
    for(int i = 0; i < children.size(); i++)
    {
        delete children[i];
    }
}
