class Solution {
public:
    vector<string> fizzBuzz(int n)
{
    vector<string> resultVector;
    string result;
    bool flag;
    for (int i = 1; i <= n; i++)
    {
        flag = 0;
        result = "";
        if (i % 3 == 0){
            result += "Fizz";
        flag = 1;}
        if (i % 5 == 0){
            result += "Buzz";
        flag = 1;
        }
        if (flag == 0)
            result += to_string(i);
        resultVector.push_back(result);
    }
    return resultVector;
}
};