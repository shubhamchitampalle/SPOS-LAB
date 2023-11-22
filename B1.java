import java.io.*;
import java.util.*;
class B1{
	static{
		System.loadLibrary("B1");
	}
	private native int add(int a, int b);
	private native int sub(int a, int b);
	private native int mult(int a, int b);
	private native int div(int a, int b);
	
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int a, b,ch;
		System.out.println("\nEnter value of a :");
		a=sc.nextInt();
		System.out.println("\nEnter value of b :");
		b=sc.nextInt();
		do{
			System.out.println("\nEnter your choice :");
			ch=sc.nextInt();
		switch(ch){
			case 1 : new B1().add(a,b);
			break;
			case 2 : new B1().sub(a,b);
			break;
			case 3 : new B1().mult(a,b);
			break;
			case 4 : new B1().div(a,b);
			break;
			default : System.out.println("wrong choice");
		}
		}while(ch<5);
		
	}
}


// #include <jni.h>
// #include <stdio.h>
// #include "B1.h"
// JNIEXPORT int JNICALL Java_B1_add(JNIEnv *env,jobject onj, jint a, jint b){
// 	printf("\n%d + %d=%d\n",a,b,(a+b));
// 	return 0;
// }

// JNIEXPORT int JNICALL Java_B1_sub(JNIEnv *env,jobject onj, jint a, jint b){
// 	printf("\n%d - %d=%d\n",a,b,(a-b));
// 	return 0;
// }

// JNIEXPORT int JNICALL Java_B1_mult(JNIEnv *env,jobject onj, jint a, jint b){
// 	printf("\n%d * %d=%d\n",a,b,(a*b));
// 	return 0;
// }

// JNIEXPORT int JNICALL Java_B1_div(JNIEnv *env,jobject onj, jint a, jint b){
// 	printf("\n%d / %d=%d\n",a,b,(a/b));
// 	return 0;
// }



// javac B1.java 
// javah B1
// gcc -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libbi.so B1.c
//java -Djava.library.path=. B1




