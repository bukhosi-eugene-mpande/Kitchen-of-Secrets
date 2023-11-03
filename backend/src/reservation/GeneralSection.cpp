#include "GeneralSection.h"

GeneralSection::GeneralSection() : Section("General Section",10) {
    for(int i=0;i<10;i++){
        std::shared_ptr<GeneralTable> table = std::make_shared<GeneralTable>();
        this->tables.push_back(table); 
    }
}

GeneralSection::~GeneralSection() {

}