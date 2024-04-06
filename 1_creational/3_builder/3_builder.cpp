#include <iostream>


class ReportData
{
public:
    std::string getHeader()
    {
        return "HEADER HEADER HEADER HEADER";
    }
    std::string getContent()
    {
        return "CONTENT CONTENT CONTENT";
    }
    std::string getFooter()
    {
        return "FOOTER FOOTER FOOTER";
    }
};

class Report
{
public:
    std::string type;
    std::string header;
    std::string content;
    std::string footer;

    virtual void show() = 0;

    
};

class PdfReport : public Report
{
public:
    virtual void show() override
    {
        std::cout << "PDF_REPORT\n";
        std::cout << this->type << '\n';
        std::cout << this->header << '\n';
        std::cout << this->content << '\n';
        std::cout << this->footer << '\n';
    }
};

class ExcelReport : public Report
{
public:
    virtual void show() override
    {
        std::cout << "EXCEL_REPORT\n";
        std::cout << this->type << '\n';
        std::cout << this->header << '\n';
        std::cout << this->content << '\n';
        std::cout << this->footer << '\n';
    }
};



class Builder
{
public:
    ReportData* reportData;
    Report* report = nullptr;


    Builder(ReportData* reportData):
        reportData{reportData}
    {}

    virtual void setType() = 0;
    virtual void setHeader() = 0;
    virtual void setContent() = 0;
    virtual void setFooter() = 0;

    Report* getReport()
    {
        return this->report;
    }

    virtual ~Builder() {}
};

class PdfBuilder: public Builder
{
public:
    PdfBuilder(ReportData* reportData):
        Builder{reportData}
    {
        this->report = new PdfReport{};
    }

    virtual void setType() override
    {
        this->report->type = "PDF type";
    }
    virtual void setHeader() override
    {
        this->report->header = reportData->getHeader();
    }
    virtual void setContent() override
    {
        this->report->content = reportData->getContent();
    }
    virtual void setFooter() override
    {
        this->report->footer = reportData->getFooter();
    }
};

class ExcelBuilder : public Builder
{
public:
    ExcelBuilder(ReportData* reportData) :
        Builder{ reportData }
    {
        this->report = new ExcelReport{};
    }

    virtual void setType() override
    {
        this->report->type = "Excel type";
    }
    virtual void setHeader() override
    {
        this->report->header = reportData->getHeader();
    }
    virtual void setContent() override
    {
        this->report->content = reportData->getContent();
    }
    virtual void setFooter() override
    {
        this->report->footer = reportData->getFooter();
    }
};



class ReportDirector
{
public:
    Report* buildFullReport(Builder* builder)
    {
        builder->setType();
        builder->setHeader();
        builder->setContent();
        builder->setFooter();

        return builder->getReport();
    }
};



int main()
{
    ReportData* reportData = new ReportData{};

    /*Builder* builder = new PdfBuilder(reportData);
    builder->setType();
    builder->setFooter();
    builder->setContent();

    Report* report = builder->getReport();
    report->show();*/



    ReportDirector* director = new ReportDirector{};

    Report* report = director->buildFullReport(new ExcelBuilder{ reportData });
    report->show();
}

