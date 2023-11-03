#include "PrivateSection.h"

PrivateSection::PrivateSection() : Section("Private Section",10) {
    for(int i=0;i<10;i++){
        std::shared_ptr<PrivateTable> table = std::make_shared<PrivateTable>();
        this->tables.push_back(table); 
    }
}

PrivateSection::~PrivateSection() {

}