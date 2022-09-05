// comprator class
// hacker rank

import java.util.*;

class comprator{
    boolean compare(int a, int b){
        if(a>b){
            return true;
        }
        else{
            return false;
        }
    }

    boolean compare(String a, String b){
        if(a.length()>b.length()){
            return true;
        }
        else{
            return false;
        }
    }

    boolean compare(int a[], int b[]){
        int sum1=0;
        int sum2=0;
        for(int i=0;i<a.length;i++){
            sum1+=a[i];
        }
        for(int i=0;i<b.length;i++){
            sum2+=b[i];
        }
        if(sum1>sum2){
            return true;
        }
        else{
            return false;
        }
    }
}