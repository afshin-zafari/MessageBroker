#include "InfoOutput.h"

namespace king::test 
{
    class InfoFileOutput: public InfoOutput
    {
        public:
        
        bool ShowMessage(const Message &, bool)  const override;
        bool ShowInfo   (const string &)         const override;
        bool ShowMenu   (const vector<string> &) const override;
        bool ClearScreen()                       const override;        

    };
    typedef unique_ptr<InfoFileOutput> InfoFileOutputPtr;
}