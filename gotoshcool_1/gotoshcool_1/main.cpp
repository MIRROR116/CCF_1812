//
//  main.cpp
//  gotoschool_1812_1
//
//  Created by mirror_z on 2019/2/21.
//  Copyright © 2019年 mirror. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    // insert code here...
    int r;//red
    int y;//yellow
    int g;//green
    int n;//street+light
    int k;//flag
    int t;//now time
    int total=0;//total time
    cin>>r>>y>>g;
    cin>>n;
    while(0!=(n--)){
        cin>>k>>t;
        if(0==k)
            total+=t;
        else if(1==k)
            total+=t;
        else if(2==k)
            total+=r+t;
    }
    cout<<total<<endl;
    return 0;
}
