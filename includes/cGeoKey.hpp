//
//  cGeoKey.hpp
//  Project
//
//  Created by Antoine Cottin on 11/12/2015.
//
//

#ifndef cGeoKey_hpp
#define cGeoKey_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "PulseWavesDefs.hpp"
#include "cVlr.hpp"



#pragma pack(push, 1)
class cGeoKeyDir_subKey
{
    
public:
    
    U16     gKeyID_;
    U16     gKeyTiffTagLocation_;
    U16     gKeyCount_;
    U16     gKeyValueOffset_;
    
    cGeoKeyDir_subKey();
    ~cGeoKeyDir_subKey(){};
    
    void read(std::fstream*);

    void print() const;
    

    
};
#pragma pack(pop)



#pragma pack(push, 1)
class cGeoKeyDir
{
    
public:
    
    U16     gKeyDirectoryVersion_;
    U16     gKeyRevision_;
    U16     gKeyMinorRevision_;
    U16     gKeyNumberOfKeys_;
    
    cGeoKeyDir();
    ~cGeoKeyDir()
    {
        cGeoKeySubDirArr_ = 0;
    };
    
    void read(std::fstream*);
    void readGeoKeySubDir(std::fstream*);
    void print() const;
    
private:
    
    cGeoKeyDir_subKey* cGeoKeySubDirArr_;
    
    
};
#pragma pack(pop)



#pragma pack(push, 1)
class cGeoKeyDblPrm : public cVlrHeader
{
    
public:
    
    cGeoKeyDblPrm();
    ~cGeoKeyDblPrm(){};
    
    void read(std::fstream*);
    void print() const;
    
private:
    
    std::vector<U64>* vecArr_;

    
};
#pragma pack(pop)




#pragma pack(push, 1)
class cGeoKeyAscii : public cVlrHeader
{
    
public:
    
    
    cGeoKeyAscii();
    ~cGeoKeyAscii(){};
    
    void read(std::fstream*);
    void print() const;
    
private:
    
    U8* vecArr_;
//    std::vector<U8>* vecArr_;
    
};
#pragma pack(pop)




#pragma pack(push, 1)
class cGeoKey : public cVlrHeader
{
    
public:
    
    cGeoKey(std::fstream*, U32*);
    ~cGeoKey(){};
    
    void read(std::fstream*);
    void print() const;
    
private:
    
    cGeoKeyDir*     cGeoKeyDir_;
    cGeoKeyDblPrm*  cGeoKeyDP_;
    cGeoKeyAscii*   cGeoKeyAscii_;
    
};
#pragma pack(pop)


#endif /* cGeoKey_hpp */
