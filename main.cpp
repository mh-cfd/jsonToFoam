#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "json.hpp"
#include "cJSON.h"

using json = nlohmann::json;
char dir[1024];

int main()
{



    sprintf(dir,"%s",__FILE__);
    dir[strlen(dir)-9]=0; //hack to get source directory

    printf("Program started, source dir is %s \n ", dir);

    char fname[1024];
    sprintf(fname,"%s/test.json",dir);
    /*
//parsing of a file:=================================
    std::ifstream f(fname);
    json data = json::parse(f);

    data["pi"] = 2.0;
    // pretty print with indent of 4 spaces
    std::cout << std::setw(4) << data << '\n';

//forking with of a file:=================================
    // create a JSON object
    json j =
    {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {
            "answer", {
                {"everything", 42}
            }
        },
        {"list", {1, 0, 2}},
        {
            "object", {
                {"currency", "USD"},
                {"value", 42.99}
            }
        }
    };

    // add new values
    j["new"]["key"]["value"] = {"another", "list"};

    // count elements
    auto s = j.size();
    j["size"] = s;

    // pretty print with indent of 4 spaces
    //std::cout << std::setw(4) << j << '\n';
    */

    char * buffer = 0;
    long length;
    FILE * f = fopen (fname, "rb");

    if (f)
    {
      fseek (f, 0, SEEK_END);
      length = ftell (f);
      fseek (f, 0, SEEK_SET);
      buffer = (char*)malloc (length);
      if (buffer)
      {
        fread (buffer, 1, length, f);
      }
      fclose (f);
      buffer[length-1] = 0;
    }

    printf("file is read, length is %d contents:\n %s\n",length,buffer);
    if (buffer)
    {
        cJSON *json = cJSON_Parse(buffer);
        printf("json parsed \n");
        char *string = cJSON_Print(json);
        printf("json is printed \n %s \n",string);
      // start to process your data / extract strings here...
    }

}
