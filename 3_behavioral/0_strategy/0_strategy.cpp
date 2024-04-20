#include <iostream>


enum ItemType
{
    FILE_TYPE,
    DIR_TYPE,
};

class ICompression
{
public:
    virtual std::string compressFile(std::string filePath) = 0;
    virtual std::string commpressDirectory(std::string dirPath) = 0;
};


class ZipCompression: public ICompression
{
public:
    virtual std::string compressFile(std::string filePath) override
    {
        return "zip file: " + filePath;
    }
    virtual std::string commpressDirectory(std::string dirPath) override
    {
        return "zip dir: " + dirPath;
    }
};

class RarCompression : public ICompression
{
public:
    virtual std::string compressFile(std::string filePath) override
    {
        return "rar file: " + filePath;
    }
    virtual std::string commpressDirectory(std::string dirPath) override
    {
        return "rar dir: " + dirPath;
    }
};


class Compressor
{
private:
    ICompression* compression;

public:
    Compressor(ICompression* compression):
        compression{compression}
    {}

    void setCompression(ICompression* compression)
    {
        this->compression = compression;
    }

    std::string makeArchive(std::string path, ItemType itemType)
    {
        switch (itemType)
        {
        case ItemType::FILE_TYPE:
            return this->compression->compressFile(path);
            break;
        case ItemType::DIR_TYPE:
            return this->compression->commpressDirectory(path);
            break;
        }
    }
};



int main()
{
    ICompression* zip = new ZipCompression{};
    ICompression* rar = new RarCompression{};

    Compressor* compressor = new Compressor{ zip };
    compressor->setCompression(rar);

    std::cout << compressor->makeArchive("test.docx", ItemType::FILE_TYPE);
}

