//Created by Sariah Warren 5/4/21
//If the user chooses to do so, a CSV file can be exported listing all the files, their technicalinformation 
//(sample rates, etc.), and the file metadata. 
//If no metadata exists, the phrase “Nometadata present” should be included in the description for that file.
#ifndef CSV_H
#define CSV_H

class CSV
{
public:
    template <typename T>
    void CSVExport(const T& t);
};
#endif