/***
 * @Description: 
 * @version: 
 * @Author: Rundong Wang
 * @Date: 2023-02-18 16:21:30
 * @LastEditors: 
 * @LastEditTime: 2023-02-18 16:45:52
 */
int gcd(int a, int b){
    return b==0 ? a: gcd(b, a % b);
}