#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int keypad[4][3];
pair<int, int> nowLeft;
pair<int, int> nowRight;

string solution(vector<int> numbers, string hand) 
{  
    // *: 숫자 10, #: 숫자 11
    string answer = ""; // 결과값 저장용 string
    
    // 키패드 위치 저장  
    int n=1;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            keypad[i][j] = n;
            n += 1;
        }
    }
    keypad[3][0] = 10;
    keypad[3][1] = 0;
    keypad[3][2] = 11;
    
    nowLeft.first = 3;
    nowLeft.second = 0;
    nowRight.first = 3;
    nowRight.second = 2;
    
    cout << "numbers 길이: " << numbers.size() << "\n";
    // numbers에 들어있는 숫자 차례로    
    for(int k=0; k<numbers.size(); k++)
    {
        // cout << k << "번째 눌러야 하는 손 찾기" << "\n";
        int num = numbers[k];
        int keypad_i;
        int keypad_j;
        int leftDiff;
        int rightDiff;
        
            // 키패드에서 일치하는 숫자 찾기
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<3; j++)
                {
                    if(num == keypad[i][j])
                    {
                        // cout << i << "번째 눌러야하는 키패드 좌표" << "{" << i << " " << j << "}\n";
                        keypad_i = i;
                        keypad_j = j;
                        
                        if(num==1 || num==4 || num==7) // 1, 4, 7일 때
                        {    
                            nowLeft.first = keypad_i;
                            nowLeft.second = keypad_j;            

                            answer += "L";
                        }
                        else if(num==3 || num==6 || num==9) // 3, 6, 9일 때
                        {
                            nowRight.first = keypad_i;
                            nowRight.second = keypad_j;

                            answer += "R";
                        }
                        else // 2, 5, 8, 0 일때
                        {
                            leftDiff = abs(i-nowLeft.first) + abs(j-nowLeft.second);
                            rightDiff = abs(i-nowRight.first) + abs(j-nowRight.second);
                            
                            // 문자열에 이동한 숫자 추가
                            if(leftDiff < rightDiff || (leftDiff==rightDiff && hand=="left") ) 
                            // 왼손이 움직인 경우
                            {
                                nowLeft.first = keypad_i;
                                nowLeft.second = keypad_j;            

                                answer += "L";
                                cout << "L\n";
                            }
                            else if(rightDiff < leftDiff || (leftDiff==rightDiff && hand=="right")) 
                            // 오른손이 움직인 경우
                            {
                                nowRight.first = keypad_i;
                                nowRight.second = keypad_j;

                                answer += "R";
                            }
                        }
                        
                    }
                }
            }

            
        }
    return answer;
}
             