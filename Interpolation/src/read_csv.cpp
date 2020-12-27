#include"read_csv.h"
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
std::vector<std::vector<std::string>> read_csv(std::string file_path)
{
    // File pointer 
    std::ifstream fin(file_path.c_str());
    std::vector<std::string> content;
    std::vector<std::vector<std::string>> content_separated;
    
  
    // Open an existing file 
    if(!fin.is_open()) throw std::runtime_error("Could not open file");
    std::string line;
     while (getline(fin,line))
    {
        std::stringstream s(line);
        //std::cout << line << '\n';
        content.push_back(line);
        while(s.good())
        {
            std::string substr;
            getline( s, substr, ',' );
        }
    }
    for(int i = 0;i<content.size();i++)
    {
        std::vector<std::string> temp;
        std::stringstream s(content[i]);
        while(s.good())
        {
            std::string substr;
            getline( s, substr, ',' );
            temp.push_back(substr);
        }
        content_separated.push_back(temp);
    }
    fin.close();
    //std::cout<<content.size()<<std::endl;
    //std::cout<<content_separated.size()<<std::endl;
    //std::cout<<content_separated[0].size()<<std::endl;
    return content_separated;
}
void write_csv(std::string file_path,std::vector<std::vector<double>> data)
{
    std::ofstream myFile(file_path);
    for(int i = 0;i<data.size();i++)
    {
        for(int j = 0;j<data[0].size();j++)
        {
            myFile << data[i][j] << ",";
        }
        myFile << "\n";
    }
    myFile.close();
}