
//#include "BackwardsChaining.hpp"
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <stack>
#include <vector>


/*
 * Only LCC works. But not completely.
 */





int determine_Conclusion(std::string InputCancer, std::map<int, std::string> conclusion);
void instantiate(std::map<int, std::string> clause, std::string variableList[], std::stack<std::string> stack, int stackNumber, bool answers[]);
void determine_Jump(bool answers[31], int * i, int *rule, int *formula, std::stack<std::string> stack);
void PrintStack(std::stack<std::string> stack);

int main() {


    std::string UserInputCancer;
    std::stack<int> clauseStack;
    std::map<int, std::string> conclusionList;
    std::string variableList[31];
    std::map<int, std::string> clauseVariableList;
    std::stack<std::string> stack;
    bool Answers[31];

    for(int i = 0; i < 31; i++){
        Answers[i] = false;
    }

    int stackNumber = 0;

    int stackPointer = 11;

//Add all conclusions in conclusion list.
    conclusionList[1] = "LCC";      //Lung Cancer Check - intermediate conclusion
    conclusionList[2] = "OF";       //Other Factors: Smoker without lung cancer symptoms
    conclusionList[3] = "OF";       //Excess body weight
    conclusionList[4] = "OF";       //Low physical activity
    conclusionList[5] = "OF";       //Excess alcohol consumption
    conclusionList[6] = "OF";       //Excess meat consumption
    conclusionList[7] = "NC";       //No cancer identified/beyond scope
    conclusionList[8] = "CCC";      //Colon Cancer Check - intermediate conclusion
    conclusionList[9] = "PCC";      //Pancreatic Cancer Check - intermediate conclusion
    conclusionList[10] = "BCC";     //Breast Cancer Check - intermediate conclusion
    conclusionList[11] = "LC";      //Leukemia check - intermediate conclusion
    conclusionList[12] = "NC";      //No cancer identified/beyond scope
    conclusionList[13] = "RETEST";  //No cancer identified, Monitor and retest
    conclusionList[14] = "CANCER";  //Lung cancer, advanced SCLC
    conclusionList[15] = "CANCER";  //Lung cancer, early SCLC
    conclusionList[16] = "CANCER";  //Lung cancer, advanced NSCLC
    conclusionList[17] = "CANCER";  //Lung cancer, early NSCLC
    conclusionList[18] = "RETEST";  //No cancer identified, Monitor and retest
    conclusionList[19] = "CANCER";  //Colon cancer, early with few polyps/tumors
    conclusionList[20] = "CANCER";  //Colon cancer, early with extensive polyps/tumors
    conclusionList[21] = "CANCER";  //Colon cancer, late stage
    conclusionList[22] = "RETEST";  //No cancer identified, Monitor and retest
    conclusionList[23] = "RETEST";  //No cancer identified, Monitor and retest
    conclusionList[24] = "CANCER";  //Pancreatic cancer, localized
    conclusionList[25] = "CANCER";  //Pancreatic cancer, metastatic
    conclusionList[26] = "RETEST";  //No cancer identified, Monitor and retest
    conclusionList[27] = "RETEST";  //No cancer identified, Monitor and retest
    conclusionList[28] = "CANCER";  //Breast cancer, invasive
    conclusionList[29] = "CANCER";  //Breast cancer, metastatic
    conclusionList[30] = "CANCER";  //Breast cancer, ductal
    conclusionList[31] = "RETEST";  //No cancer identified, Monitor and retest
    conclusionList[32] = "CANCER";  //Leukemia, acute lymphoblastic
    conclusionList[33] = "CANCER";  //Leukemia, acute lymphoblastic, of the brain
    conclusionList[34] = "CANCER";  //Leukemia, acute myeloid
    conclusionList[35] = "CANCER";  //Leukemia, acute myeloid, of the brain
    conclusionList[36] = "CANCER";  //Leukemia, hairy cell, without growth
    conclusionList[37] = "CANCER";  //Leukemia, hairy cell, with growth
    //conclusionList[x//[x][0] = "";


//Add all variables that lead to the conclusions up above.
    variableList[0] = "Smoker";
    variableList[1] = "Symptom 1: Lung cancer symptoms";
    variableList[2] = "Lung imaging: Suspicious Mass";
    variableList[3] = "Excess body weight";
    variableList[4] = "Low physical activity";
    variableList[5] = "Excess alcohol consumption";
    variableList[6] = "Excess meat consumption";
    variableList[7] = "Symptom 2: Colon cancer symptoms";
    variableList[8] = "Symptom 3: Pancreatic cancer symptoms";
    variableList[9] = "Symptom 4: Breast cancer symptoms";
    variableList[10] = "Symptom 5: Leukemia symptoms";
    variableList[11] = "Lung imaging: Suspicious Mass";
    variableList[12] = "Lung biopsy: SCLC?";
    variableList[13] = "SCLC stage: advanced?";
    variableList[14] = "NSCLC stage: advanced?";
    variableList[15] = "Colonoscopy";
    variableList[16] = "Colon biopsy early?";
    variableList[17] = "Colon polyp/tumor few?";
    variableList[18] = "Pancreas imaging";
    variableList[19] = "Pancreas biopsy: early stage?";
    variableList[20] = "Pancreas metastatic";
    variableList[21] = "Breast imaging";
    variableList[22] = "Breast biopsy";
    variableList[23] = "Milk duct tumor";
    variableList[24] = "Breast metastatic";
    variableList[25] = "Leukemia lab test";
    variableList[26] = "Hairy Cell Leukemia lab test";
    variableList[27] = "Acute Myeloid Leukemia test";
    variableList[28] = "Acute Lymphoblastic Leukemia spread to the brain";
    variableList[29] = "Acute Myeloid Leukemia spread to the brain";
    variableList[30] = "Hairy Cell Leukemia growing";
    //variableList[x][0] = "";

//Add all Clause variables with clause number

    //Rule number 10
    clauseVariableList[1] = "Smoker";
    clauseVariableList[2] = "Symptom 1: Lung cancer symptoms";
    //Rule number 20
    clauseVariableList[7] = "Smoker";
    clauseVariableList[8] = "Symptom 1: Lung cancer symptoms";
    //Rule number 30
    clauseVariableList[13] = "Excess body weight";
    //Rule number 40
    clauseVariableList[19] = "Low physical activity";
    //Rule number 50
    clauseVariableList[25] = "Excess alcohol consumption";
    //Rule number 60
    clauseVariableList[31] = "Excess meat consumption";
    //Rule number 70
    clauseVariableList[37] = "Smoker";
    clauseVariableList[38] = "Excess body weight";
    clauseVariableList[39] = "Low physical activity";
    clauseVariableList[40] = "Excess alcohol consumption";
    clauseVariableList[41] = "Excess meat consumption";
    //Rule number 80
    clauseVariableList[43] = "Symptom 2: Colon cancer symptoms";  //Other Factors, From Conclusion List

    //Rule number 90
    clauseVariableList[49] = "OF";  //Other Factors, From Conclusion List
    clauseVariableList[50] = "Symptom 2: Colon cancer symptoms";
    clauseVariableList[51] = "Symptom 3: Pancreatic cancer symptoms";
    //Rule number 100
    clauseVariableList[55] = "OF";  //Other Factors, From Conclusion List
    clauseVariableList[56] = "Symptom 2: Colon cancer symptoms";
    clauseVariableList[57] = "Symptom 3: Pancreatic cancer symptoms";
    clauseVariableList[58] = "Symptom 4: Breast cancer symptoms";
    //Rule number 110
    clauseVariableList[61] = "OF";  //Other Factors, From Conclusion List
    clauseVariableList[62] = "Symptom 2: Colon cancer symptoms";
    clauseVariableList[63] = "Symptom 3: Pancreatic cancer symptoms";
    clauseVariableList[64] = "Symptom 4: Breast cancer symptoms";
    clauseVariableList[65] = "Symptom 5: Leukemia symptoms";
    //Rule number 120
    clauseVariableList[67] = "OF";  //Other Factors, From Conclusion List
    clauseVariableList[68] = "Symptom 2: Colon cancer symptoms";
    clauseVariableList[69] = "Symptom 3: Pancreatic cancer symptoms";
    clauseVariableList[70] = "Symptom 4: Breast cancer symptoms";
    clauseVariableList[71] = "Symptom 5: Leukemia symptoms";
    //Rule number 130
      //Lung Cancer Check, from Conclusion List
    clauseVariableList[73] = "Lung imaging: Suspicious Mass";
    //Rule number 140
      //Lung Cancer Check, from Conclusion List
    clauseVariableList[79] = "Lung biopsy: SCLC?";
    clauseVariableList[80] = "SCLC stage: advanced?";
    //Rule number 150
       //Lung Cancer Check, from Conclusion List
    clauseVariableList[85] = "Lung imaging: Suspicious Mass";
    clauseVariableList[86] = "Lung biopsy: SCLC?";
    clauseVariableList[87] = "SCLC stage: advanced?";
    //Rule number 160
       //Lung Cancer Check, from Conclusion List
    clauseVariableList[91] = "Lung imaging: Suspicious Mass";
    clauseVariableList[92] = "Lung biopsy: SCLC?";
    clauseVariableList[93] = "NSCLC stage: advanced?";
    //Rule number 170
        //Lung Cancer Check, from Conclusion List
    clauseVariableList[97] = "Lung imaging: Suspicious Mass";
    clauseVariableList[98] = "Lung biopsy: SCLC?";
    clauseVariableList[99] = "NSCLC stage: advanced?";
    //Rule number 180
    //Colon Cancer Check, from Conclusion List
    clauseVariableList[103] = "Colonoscopy";
    //Rule number 190
      //Colon Cancer Check, from Conclusion List
    clauseVariableList[109] = "Colonoscopy";
    clauseVariableList[110] = "Colon biopsy early?";
    clauseVariableList[111] = "Colon polyp/tumor few?";
    //Rule number 200
      //Colon Cancer Check, from Conclusion List
    clauseVariableList[115] = "Colonoscopy";
    clauseVariableList[116] = "Colon biopsy early?";
    clauseVariableList[117] = "Colon polyp/tumor few?";
    //Rule number 210
      //Colon Cancer Check, from Conclusion List
    clauseVariableList[121] = "Colonoscopy";
    clauseVariableList[122] = "Colon biopsy early?";
    //Rule number 220
       //Pancreatic Cancer Check, from Conclusion List
    clauseVariableList[127] = "Pancreas imaging";
    //Rule number 230
      //Pancreatic Cancer Check, from Conclusion List
    clauseVariableList[133] = "Pancreas imaging";
    clauseVariableList[134] = "Pancreas biopsy: early stage?";
    //Rule number 240
      //Pancreatic Cancer Check, from Conclusion List
    clauseVariableList[139] = "Pancreas imaging";
    clauseVariableList[140] = "Pancreas biopsy: early stage?";
    clauseVariableList[141] = "Pancreas metastatic";
    //Rule number 250
      //Pancreatic Cancer Check, from Conclusion List
    clauseVariableList[145] = "Pancreas imaging";
    clauseVariableList[146] = "Pancreas biopsy: early stage?";
    clauseVariableList[147] = "Pancreas metastatic";
    //Rule number 260
      //Breast Cancer Check, from Conclusion List
    clauseVariableList[151] = "Breast imaging";
    //Rule number 270
      //Breast Cancer Check, from Conclusion List
    clauseVariableList[157] = "Breast imaging";
    clauseVariableList[158] = "Breast biopsy";
    //Rule number 280
       //Breast Cancer Check, from Conclusion List
    clauseVariableList[163] = "Breast imaging";
    clauseVariableList[164] = "Breast biopsy";
    clauseVariableList[165] = "Milk duct tumor";
    clauseVariableList[166] = "Breast metastatic";
    //Rule number 290
     //Breast Cancer Check, from Conclusion List
    clauseVariableList[169] = "Breast imaging";
    clauseVariableList[170] = "Breast biopsy";
    clauseVariableList[171] = "Milk duct tumor";
    clauseVariableList[172] = "Breast metastatic";
    //Rule number 300
      //Breast Cancer Check, from Conclusion List
    clauseVariableList[175] = "Breast imaging";
    clauseVariableList[176] = "Breast biopsy";
    clauseVariableList[177] = "Milk duct tumor";
    //Rule number 310
       //Leukemia check, from Conclusion List
    clauseVariableList[181] = "Leukemia lab test";
    //Rule number 320
        //Leukemia check, from Conclusion List
    clauseVariableList[187] = "Leukemia lab test";
    clauseVariableList[188] = "Hairy Cell Leukemia lab test";
    clauseVariableList[189] = "Acute Myeloid Leukemia test";
    clauseVariableList[190] = "Acute Lymphoblastic Leukemia spread to the brain";
    //Rule number 330
    //Leukemia check, from Conclusion List
    clauseVariableList[193] = "Leukemia lab test";
    clauseVariableList[194] = "Hairy Cell Leukemia lab test";
    clauseVariableList[195] = "Acute Myeloid Leukemia test";
    clauseVariableList[196] = "Acute Lymphoblastic Leukemia spread to the brain";
    //Rule number 340
     //Leukemia check, from Conclusion List
    clauseVariableList[199] = "Leukemia lab test";
    clauseVariableList[200] = "Hairy Cell Leukemia lab test";
    clauseVariableList[201] = "Acute Myeloid Leukemia test";
    clauseVariableList[202] = "Acute Myeloid Leukemia spread to the brain";
    //Rule number 350
      //Leukemia check, from Conclusion List
    clauseVariableList[205] = "Leukemia lab test";
    clauseVariableList[206] = "Hairy Cell Leukemia lab test";
    clauseVariableList[207] = "Acute Myeloid Leukemia test";
    clauseVariableList[208] = "Acute Myeloid Leukemia spread to the brain";
    //Rule number 360
        //Leukemia check, from Conclusion List
    clauseVariableList[211] = "Leukemia lab test";
    clauseVariableList[212] = "Hairy Cell Leukemia lab test";
    clauseVariableList[213] = "Hairy Cell Leukemia growing";
    //Rule number 370
       //Leukemia check, from Conclusion List
    clauseVariableList[217] = "Leukemia lab test";
    clauseVariableList[218] = "Hairy Cell Leukemia lab test";
    clauseVariableList[219] = "Hairy Cell Leukemia growing";


    //Next we need to get the conclusion that the user wants
    std::cout << "enter conclusion: ";
    std::cin >> UserInputCancer;
    stackNumber = determine_Conclusion(UserInputCancer, conclusionList);
    if(stackNumber <= 37){
        instantiate(clauseVariableList,variableList, stack, stackNumber, Answers);
    }
    PrintStack(stack);

}

int determine_Conclusion(std::string InputCancer, std::map<int, std::string> conclusion){
    int answer = 0;
    for(auto it = conclusion.begin(); it != conclusion.end(); ++it){
        std::cout << "it->first = " << it->first << std::endl;
        std::cout << "it->second = " << it->second << std::endl;
        if(it->second == InputCancer){
            answer = it->first;

            return answer;
        }
    }
    return answer;
}

void instantiate(std::map<int, std::string> clause, std::string variableList[31], std::stack<std::string> stack, int stackNumber, bool answers[]) {
    int RuleNumber = stackNumber * 10;
    std::cout << "RuleNumber = " << RuleNumber << std::endl;
    int Origin = RuleNumber;
    int i = 0;
    int j = 0;
    std::string x;
    int Formula = 6 * (RuleNumber / 10 - 1) + 1;
    std::string y;
    y = clause[Formula];
    stack.push(y);

    std::cout << "CLAUSE LOCATION:" << Formula << " " << "Symptom: " << '\n';
    while (i < 31) {
        if (y == variableList[i]){
            std::cout << "In the Loop" << '\n';
            std::cout << y << "?" << '\n';
        std::cin >> x;
        std::cout << '\n';
        stack.push(y);

            if (x == "YES") {
            answers[i] = true;
            Formula++;

            } else if (x == "NO") {
            answers[i] = false;
            Formula++;

            }
        y = clause[Formula];

        }else if (y == "") {
            /* If y is empty and there is no jump. We conclude, because we didn't jump. Example would be if someone said no to smoker,
             * Other Factors: Excess body weight, Other Factors: Low physical activity, Other Factors: Excess alcohol comsumption,
             * and Other Factors: Excess meat consumption
            */
            std::cout << i << ": I before jump" << '\n';

                determine_Jump(answers, &i, &RuleNumber, &Formula, stack);

            y = clause[Formula];
        }else{
            // For Some reason it says that these two are not equal. But I've copied and pasted the two and nothing changes.
            std::cout << y << 1 << '\n';
            std::cout << clause[Formula] << 2 << '\n';
            std::cout << variableList[i] << 3 << '\n';
            std::cout << '\n';
        }
        std::cout << i << " = I" << '\n';
        i++;
    }
}



void determine_Jump(bool answers[31], int * i, int *ruleNumber, int *Formula, std::stack<std::string> stack){


    /*
     *
     * Only LCC works right now. But it doesn't show meat consumption.
     * Take a look, if you cant find anything then I'll be working on it a little later.
     *
     *
     */
    switch (*i) {
        //Case 0 is Smoker. This checks if the user said yes or no to smoking.
        case 2:

            if (answers[1] && answers[0]) {
                    std::cout << "in case 2" << std::endl;
                *ruleNumber = 130;
                *Formula = 6 * (*ruleNumber / 10 - 1) + 1;
                std::cout << *i << '\n';
            }else if(!answers[0]){
                std::cout << "in case 2" << std::endl;
                *ruleNumber = 30;
                *Formula = 6 * (*ruleNumber / 10 - 1) + 1;

            }else if(answers[0] && !answers[1]){
                std::cout << "in case 2" << std::endl;
                *ruleNumber = 80;
                *Formula = 6 * (*ruleNumber / 10 - 1) + 1;
            }
            std::cout << "Case 1" << '\n';
            std::cout << "Rule Number: " << *ruleNumber << '\n';
            std::cout << *i << '\n';
            std::cout << '\n';
            break;
        case 3:

            if(answers[3]){
                    std::cout << "in case 3" << std::endl;
                *ruleNumber = 80;
                *Formula = 6 * (*ruleNumber / 10 - 1) + 1;
            }else if(!answers[3]){
                std::cout << "in case 3" << std::endl;
                *ruleNumber = 40;
                *Formula = 6 * (*ruleNumber / 10 - 1) + 1;
            }
            std::cout << "Case 2" << '\n';
            std::cout << "Rule Number: " << *ruleNumber << '\n';
            std::cout << *i << '\n';
            std::cout << '\n';
            break;

        case 4:
            std::cout << "in case 4" << std::endl;
            if(answers[4]){
                *ruleNumber = 80;
                *Formula = 6 * (*ruleNumber / 10 - 1) + 1;
            }else if(!answers[4]){
                *ruleNumber = 50;
                *Formula = 6 * (*ruleNumber / 10 - 1) + 1;
            }
            std::cout << "Case 3:" << '\n';
            std::cout << "Rule Number: " << *ruleNumber << '\n';
            std::cout << *i << '\n';
            std::cout << '\n';
            break;
        case 5:
            std::cout << "in case 5" << std::endl;
            if(answers[5]){
                *ruleNumber = 80;
                *Formula = 6 * (*ruleNumber / 10 - 1) + 1;

            }else if(!answers[5]){

                *ruleNumber = 60;
                *Formula = 6 * (*ruleNumber / 10 - 1) + 1;
                std::cout << *Formula;
            }
            std::cout << "Case 4: alacohol consum" << '\n';
            std::cout << "Rule Number: " << *ruleNumber;
            std::cout << *i << '\n';
            std::cout << '\n';
            break;
        case 6:
            if(answers[6]){
                *ruleNumber = 80;
                *Formula = 6 * (*ruleNumber / 10 - 1) + 1;
            }else if(!answers[6]){
                *ruleNumber = 70;
                *Formula = 6 * (*ruleNumber / 10 - 1) + 1;
                std::cout << *Formula << '\n';
            }
            std::cout << "Case 5" << '\n';
            std::cout << "Rule Number: " << *ruleNumber << '\n';
            std::cout << *i << '\n';
            std::cout << '\n';
            break;
            // Ran into an issue where it doesn't show meat consumption. Take a look, if you cant fix it. Let me know.
        case 8:
            std::cout << "Hi";
    }

}
void PrintStack(std::stack<std::string> s)
{

    if (s.empty())
        return;


    std::string x = s.top();


    s.pop();


    PrintStack(s);


    std::cout << x << " ";



    s.push(x);
}
