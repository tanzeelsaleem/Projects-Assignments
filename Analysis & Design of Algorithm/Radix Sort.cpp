#include <iostream>
using namespace std;
void Radix_Sort(int size, string arr[]){
    string a[size],b[size],c[size],d[size],e[size],f[size],
    g[size],h[size],_i[size],j[size],k[size],l[size],m[size]
    ,n[size],o[size],p[size],q[size],r[size],s[size],t[size],
    u[size],v[size],w[size],x[size],y[size],z[size];
    for(int i=0; i<size; i++){
        string val = arr[i];
        char check = val[0];
        switch(check){
            case 'a':
            case 'A':{
                a[i] = val;
                break;
            }
            case 'b':
            case 'B':{
                b[i] = val;
                break;
            }
            case 'c':
            case 'C':{
                c[i] = val;
                break;
            }
            case 'd':
            case 'D':{
                d[i] = val;
                break;
            }
            case 'e':
            case 'E':{
                e[i] = val;
                break;
            }
            case 'f':
            case 'F':{
                f[i] = val;
                break;
            }
            case 'g':
            case 'G':{
                g[i] = val;
                break;
            }
            case 'h':
            case 'H':{
                h[i] = val;
                break;
            }
            case 'i':
            case 'I':{
                _i[i] = val;
                break;
            }
            case 'j':
            case 'J':{
                j[i] = val;
                break;
            }
            case 'k':
            case 'K':{
                k[i] = val;
                break;
            }
            case 'l':
            case 'L':{
                l[i] = val;
                break;
            }
            case 'm':
            case 'M':{
                m[i] = val;
                break;
            }
            case 'n':
            case 'N':{
                n[i] = val;
                break;
            }
            case 'o':
            case 'O':{
                o[i] = val;
                break;
            }
            case 'p':
            case 'P':{
                p[i] = val;
                break;
            }
            case 'q':
            case 'Q':{
                q[i] = val;
                break;
            }
            case 'r':
            case 'R':{
                r[i] = val;
                break;
            }
            case 's':
            case 'S':{
                s[i] = val;
                break;
            }
            case 't':
            case 'T':{
                t[i] = val;
                break;
            }
            case 'u':
            case 'U':{
                u[i] = val;
                break;
            }
            case 'v':
            case 'V':{
                v[i] = val;
                break;
            }
            case 'w':
            case 'W':{
                w[i] = val;
                break;
            }
            case 'x':
            case 'X':{
                x[i] = val;
                break;
            }
            case 'y':
            case 'Y':{
                y[i] = val;
                break;
            }
            case 'z':
            case 'Z':{
                z[i] = val;
                break;
            }   
        }
    }
    
    string sorted_arr[size];
    int counter=0;
    for(int i=0;i<size;i++){
        sorted_arr[counter] = a[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = b[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = c[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = d[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = e[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = f[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = g[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = h[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = _i[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = j[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = k[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = l[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = m[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = n[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = o[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = p[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = q[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = r[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = s[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = t[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = u[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = v[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = w[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = x[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = y[i];
        counter++;
    }
    for(int i=0;i<size;i++){
        sorted_arr[counter] = z[i];
        counter++;
    }
    
    cout<<"Sorted Names List"<<endl;
    for(int i=0;i<size;i++){
        cout<<sorted_arr[i]<<endl;
    }
}

int main() {
  string names_list[] = {"naveed", "ali","shahbaz","bilal","zeshan"};
  int length = sizeof(names_list)/sizeof(names_list[0]);
  cout<<"UN-Sorted Names List"<<endl;
    for(int i=0;i<length;i++){
        cout<<names_list[i]<<endl;
    }
  Radix_Sort(length,names_list);
  
  return 0;
}