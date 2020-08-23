
union test
{
  unsigned int x: 3;
  unsigned int y: 4;
  int z;
};

int main()
{
   union test t={6,20,30};

    t.x=t.z<<1;
   printf("t.x = %d, t.y = %d, t.z = %d\n",t.x, t.y, t.z);
    printf("%d",sizeof(t));
   return 0;
}
