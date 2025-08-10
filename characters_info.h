#ifndef CHARACTERS_INFO_H
#define CHARACTERS_INFO_H

#include <QString>
#include <vector>
#include <map>

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
const std::vector<QString> village_occupation{
    "trader", "fisher", "woodcutter"
};
}

namespace age{
inline std::uniform_int_distribution<> human_age(7,80);
inline std::uniform_int_distribution<> dwarf_age(25, 450);
inline std::uniform_int_distribution<> elf_age(65,750);

inline std::map<int, std::uniform_int_distribution<>> ages{
    {0, human_age}, {1, dwarf_age}, {2, elf_age}
};
}

#endif // CHARACTERS_INFO_H
