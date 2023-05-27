#include<bits/stdc++.h>
using namespace std;

struct Point{
    int y,x,z;
    Point(int y, int x, int z) : y(y), x(x), z(z) {}
    Point(){y = -1; x = -1; z = -1;}
    bool operator < (const Point& a) const {
        if(x == a.x) {
            if (y == a.y) return z < a.z;
            return y > a.y;
        }
        return x < a.x;
    }
};
/*
구조체 Point끼리 정렬하는 경우 x를 1순위로 오름차순으로 정렬하고 y가 2순위로 내림차순, z가 3순위로 오름차순 정렬한다.
초기값은 -1로 세팅해놓은 상태이다.
*/