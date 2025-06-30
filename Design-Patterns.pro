TEMPLATE = subdirs
CONFIG += console c++17
CONFIG += app_bundle
CONFIG += qt
QT = core



SUBDIRS += \
    Creational/AbstractFactory \
    Creational/Builder \
    Creational/Factory \
    Creational/Prototype \
    Creational/Singleton
