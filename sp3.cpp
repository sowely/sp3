#include <iostream>
using namespace std;
int main()
{
int n = 4;
int array[n] = {5,2,3,4};
int sum = 0;
cout<<"array"<<endl;
for (int i = 0; i < n; i++)
{
cout<<array[i]<<" ";
}
asm volatile(
".intel_syntax noprefix\n\t"
"xor ebx, ebx\n\t" 
"mov ecx, 0\n\t"
"next_iter:\n\t"
"cmp ecx, %2\n\t"
"je _close\n\t"
"xor eax, eax\n\t"
"mov eax, %1[ecx*4]\n\t"
"imul eax, eax\n\t"
"add ebx, eax\n\t"
"mov %1[ecx*4], eax\n\t"
"inc ecx\n\t"
"jmp next_iter\n\t" 
"_close:\n\t"
"mov %0, ebx\n\t"
:"=m"(sum)
:"m"(array), "m"(n)
:"eax", "ebx", "ecx"
);
cout<<endl<<"array(square)"<<endl;
for (int i = 0; i < n; i++)
{
cout<<array[i]<<" ";
};
cout<<endl<<"sum = "<<sum<<endl;
return 0;
}
