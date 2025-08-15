#ifndef CHARACTERS_INFO_H
#define CHARACTERS_INFO_H

#include <QString>
#include <QPixmap>
#include <vector>
#include <map>
#include <random>

namespace race{
const std::vector<QString> races{
    "human", "dwarf", "elf"
};
}

namespace name{
inline const std::vector<QString> human_male_names{
    "Joe", "Piter", "Simon"
};
inline const std::vector<QString> human_woman_names{
    "Maria", "Sara", "Gwen"
};
inline const std::vector<QString> drarwen_male_names{
    "Joe", "Piter", "Simon"
};
inline const std::vector<QString> dwarven_woman_names{
    "Maria", "Sara", "Gwen"
};
inline const std::vector<QString> elf_male_names{
    "Joe", "Piter", "Simon"
};
inline const std::vector<QString> elf_woman_names{
    "Maria", "Sara", "Gwen"
};

inline std::map<int,const std::vector<QString>*> names{
    std::pair<int,const std::vector<QString>*>(0, &human_male_names),
    std::pair<int,const std::vector<QString>*>(1, &human_woman_names),
    std::pair<int,const std::vector<QString>*>(2, &drarwen_male_names),
    std::pair<int,const std::vector<QString>*>(3, &dwarven_woman_names),
    std::pair<int,const std::vector<QString>*>(4, &elf_male_names),
    std::pair<int,const std::vector<QString>*>(5, &elf_woman_names),
};
}

namespace occupation{
inline const std::vector<QString> village_occupation{
    "trader", "fisher", "woodcutter"
};
}

namespace age{
inline std::normal_distribution<> human_age(35.0,10.0);
inline std::normal_distribution<> dwarf_age(200.0,50.0);
inline std::normal_distribution<> elf_age(425.0,110.0);

inline std::map<int, std::normal_distribution<>> ages{
    {0, human_age}, {1, dwarf_age}, {2, elf_age}
};
}

namespace pic{
inline std::map<QString, QString> pics{
    {"human", "D:\\Programming\\dnd-generator\\human.png"},
    {"dwarf", "D:\\Programming\\dnd-generator\\dwarf.png"},
    {"elf", "D:\\Programming\\dnd-generator\\elf.png"}
};
}

#endif // CHARACTERS_INFO_H
