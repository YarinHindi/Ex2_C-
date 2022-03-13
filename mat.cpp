#include "mat.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;
    /**
     *
     * @param colums
     * @param rows
     * @param ch1
     * @param ch2
     * @return string representing the mattress for the input we got
     *
     * in the function i loop through the columns and rows
     * and in the inside loop i am  adding to  current row the right symbol for each iteration
     * i used parmeter k that equle to the current row to know how many time i need to change
     * the symbol in each iteration when k equal to 0 i know i need to add the same symbol in the curent row
     * becuse every row symbole are symmetric, for every row i checked some condition to know which symybol to add
     * first-check:
     * if k (k equal to current row, when current row will be bigger than rows/2 than i know i need to do the same
     * process cause the mattress is palindromic for the lower rows,i kept track of which part i was with a boolean
     * parameter lowerRows)
     * was bigger than 0 means that in that row i need to change to symbole k*2 times
     * everytime i changed symbol in that condition i substract k=k-1 and when k equle to 0 the current
     * symbole will be addinig to the string until we will get to the other half of the row we can know it when
     * j>colunms -i meanninig we are in the other part of the row we need to change symbol agian until we finish with
     * that row.
     * when
     * second:check:
     * there some rows in between upperRows and lowerRows there i know the symbol need to be changed each itertion
     * it happed when  (i< rows - colums / 2 && i > colums / 2) this condition will be entred only if
     *  the rows number are greater than col numbers
     *
     *
     *
     */
    string ariel::mat(int colums, int rows, char ch1, char ch2)  {
        //execption in two cases when the rows/col input is even or less than 0
        if(rows<0 || colums<0){
            throw std::invalid_argument("not a valid input");
        }
        if(rows%2==0||colums%2==0){
            throw std::invalid_argument ("Mat size is always odd");
        }
        if (ch1 < '!' || ch2 < '!' || ch1 > '~' || ch2 > '~') {
            throw std::invalid_argument("Invalid charcters");
        }
        string ans;
        int k =0 ;//keep track how many symbol changes in each row
        bool lowerRows = false;// mattress is symmetric so we want to do the same for upper and lower rows
        int p =0;
        for(int i=0; i<rows; i++) {
            char sign = ch1;
            k = i;
            //this condition only if mattress is even
            if (rows % 2 == 0) {
                if (k >= rows / 2) {
                    k = rows - i - 1;
                    p = k;
                    lowerRows = true;
                }
            } else {
                // to update our k in the lower rows to be symmetric to upper rows
                if (k > rows / 2) {
                    k = rows - i - 1;
                    p = k;
                    lowerRows = true;
                }
            }
            for (int j = 0; j <= colums; j++) {
                //rows in between where symbol need to change each iteration
                if (k < rows - colums / 2 && k> colums / 2 && j != colums) {
                    ans += sign;
                    if (sign == ch1) {
                        sign = ch2;
                    } else {
                        sign = ch1;
                    }
                } else {
                    //end of row need to add \n
                    if (j == colums) {
                        ans += "\n";
                    } else {
                        //if we are in the upper rows and we are in second part of the row cause row is also symmetric
                        if (!lowerRows && j >= colums - i && j != colums) {
                            if (sign == ch1) {
                                sign = ch2;
                            } else {
                                sign = ch1;
                            }
                            ans += sign;
                        } else {
                            //if we are in the lower rows and we are in second part of the row cause row is also symmetric
                            if (lowerRows && j >= colums - p  && j != colums) {
                                if (sign == ch1) {
                                    sign = ch2;
                                } else {
                                    sign = ch1;
                                }
                                ans += sign;
                            } else {
                                //when k equal to 0 and we still in the first part of the row we need to add
                                //the same symbol until we reach the second part of the row
                                if (k == 0) {
                                    ans += sign;
                                } else {
                                    // for the first part of the row we changing symbol until k will be equal to 0
                                    ans += sign;
                                    if (sign == ch1) {
                                        sign = ch2;
                                    } else {
                                        sign = ch1;
                                    }
                                    k--;
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }




