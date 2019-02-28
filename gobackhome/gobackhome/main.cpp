//
//  main.cpp
//  gobackhome
//
//  Created by mirror_z on 2019/2/22.
//  Copyright © 2019年 mirror. All rights reserved.
//

#include <iostream>
typedef long long  ll;
using namespace std;

void match_time(long long total,int k,long long t,int *flag)
{
    //用于计算当前路段需要花费时间
    //total为从开始时刻到现路段开始时刻总用时
    if(k==0)
    {
        total+=t;
        return ;
    }
    
    int rgy=flag[0]+flag[1]+flag[2];
    //将r-g-y算作一个阶段
    long long rg=rgy-flag[1];
    long long yr=rgy-flag[2];
    long long gy=rgy-flag[0];
    long long time=total;
    while(time>rgy)
    {
        //减掉所有ryg阶段
        time-=rgy;
    }
    long long now_time=time+t;
    //直接计算多余用时
    if(1==k)
    //开始为红灯
    {
        if(now_time>rgy){
            //下一个红灯停留时间
            total+=(rgy+flag[0]-now_time);
        }else if(now_time>rg){
            //黄灯停留时间
            total+=(rgy-now_time+flag[0]);
        }else if(now_time>flag[0]){
            //绿灯不停
        }else{
            //第一个红灯停留时间
            total+=(flag[0]-now_time);
        }
        return;
    }else if(2==k)
    //开始为黄灯
    {
        if(now_time>rgy){total+=(rgy+flag[1]-now_time+flag[0]);}
        else if(now_time>yr){}
        else if(now_time>flag[1]){total+=(yr-now_time);}
        else{total+=(yr-now_time);}
        return;
        
    }else if(3==k)
    //开始为绿灯
    {
        if(time>rgy){}
        else if(time>gy){total+=(rgy-now_time);}
        else if(time>flag[2]){total+=(rgy-now_time);}
        else{}
        return;
    }
    
}

int main() {
    int light[3];
    //存储r,y,g，方便传入函数
    int n;
    //路段s总数
    long long total=0;
    //总用时
    
    for(int i=0;i<3;i++)
    {
        cin>>light[i];
    }
    cin>>n;
    
    int i=0;
    while(i<n)
    {
        int k;
        int t;
        cin>>k>>t;
        match_time(total,k,t,light);
        
        i++;
    }
    cout<<total;
    return 0;
}
