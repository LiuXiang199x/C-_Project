#ifndef _PCres_H_
#define _PCres_H_
#include <iostream>
#include <string>
#include "string.h"
#include <fstream>

namespace everest{
    namespace ai
    {
        class PCrest{
            public:
            int nano_res[2][2];   // 初始化不赋值的话会乱指
            std::string pics_url[2];
            PCrest();
            ~PCrest();

            private:
            void init_Params();
        };
    } // namespace ai
    
}

#endif // !_PCres_H_