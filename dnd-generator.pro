QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CharacterSheet.cpp \
    MainGeneratorWidget.cpp \
    character.cpp \
    charactergenerator.cpp \
    generatorwidget.cpp \
    main.cpp \
    menuwidget.cpp

HEADERS += \
    CharacterInfo.h \
    CharacterSheet.h \
    MainGeneratorWidget.h \
    character.h \
    charactergenerator.h \
    generatorwidget.h \
    menuwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
	generator_resources/dwarf/clan.txt \
	generator_resources/dwarf/dwarf.json \
	generator_resources/dwarf/dwarf.png \
	generator_resources/dwarf/name.txt \
	generator_resources/dwarf/surname.txt \
	generator_resources/elf/clan.txt \
	generator_resources/elf/elf.json \
	generator_resources/elf/elf.png \
	generator_resources/elf/name.txt \
	generator_resources/elf/surname.txt \
	generator_resources/human/human.json \
	generator_resources/human/human_f.png \
	generator_resources/human/human_m.png \
	generator_resources/occupation/town.txt \
	generator_resources/occupation/village.txt \
	generator_resources/races.json \
	generator_resources/settlement.txt
