# Learning algorithm


### 本次算法练习包含：
- 字符串反转
- 链表反转 
- 有序数组合并
- hash算法 
- 求无序数组中的中位数

### 字符串反转
对字符串`hello, world`，实现将其反转，结果为：`dlrow, olleh`。

- 分析：
初始化两个指针：begin 和 end，begin指向字符串起始位置，end指向字符串结尾。
在while循环的每一次遍历中，交换begin 和 end，并将begin指针向前移动，end指针向后移动，while循环退出的条件为begin>=end。

- 实现：

```c
void char_reverse(char *str) {
    
    // 指向第一个字符
    char *begin = str;
    // 指向最后一个字符
    char *end = str + strlen(str) - 1;
    
    while (begin < end) {
        
        // 交换beigin和end指针，并移动这两个指针
        char temp = *begin;
        *(begin++) = *end;
        *(end--) = temp;
    }
}
```

- 测试

```c
void testCharReverse(void) {
    char str[] = "hello, world";
    char_reverse(str);
    printf("%s\n", str);
}

```

输出结果：`dlrow, olleh`

### 单链表反转
对一个单链表进行反转，比如这个链表一共有1->2->3->4这些节点，要求反转后为4->3-2>1。

- 分析：
使用链表的头插法思想实现单链表的反转，我们初始化一个新的头结点，让其next指针指向NULL，定义一个临时p指针初始化其为链表的头结点，在进行原有链表的遍历中移动p指针，并将当前节点放到新的头结点的next指针，依次执行，当p指针指向null时退出循环。

实现：

```c
// 构造一个链表
struct Node * construcLinkedtList(void) {
    
    // 定义一个头结点
    struct Node *headP = NULL;
    // 记录当前尾结点
    struct Node *currentP = NULL;
    
    for (int i = 0; i < 5; i++) {
        // 创建当前结点
        struct Node *node = malloc(sizeof(struct Node));
        node->data = i;
        node->next = NULL;
        // 如果头结点为空，新节点就是头结点
        if (headP == NULL) {
            headP = node;
        }
        else {
            currentP->next = node;
        }
        
        // 记录当前节点
        currentP = node;
        
    }
    return headP;
}
// 对一个链表进行反转
struct Node * reverseLinkedList(struct Node *head) {
    // 定义临时指针p，初始化为头结点
    struct Node *p = head;
    // 定义一个新的链表头结点，作为反转后的链表头结点
    struct Node *newHead = NULL;
    
    while (p != NULL) {
        
        // 记录下一个结点
        struct Node *temp = p->next;
        // 当前结点的next指针指向链表头部
        p->next = newHead;
        // 更改新链表头部为当前结点
        newHead = p;
        // 移动p指针
        p = temp;
    }
    // 返回反转后的链表头结点
    return newHead;
}
//// 打印链表中的所有数据
void printinkedtList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("node is %d \n", temp->data);
        temp = temp->next;
    }
}
```

- 测试：

```c
void testLinkedListReverse(void) {
    struct Node *linkedList = construcLinkedtList();
    printinkedtList(linkedList);
    printf("__________\n");
    struct Node *newLinkedList = reverseLinkedList(linkedList);
    printinkedtList(newLinkedList);
    
}
```

输出结果：
```
node is 0 
node is 1 
node is 2 
node is 3 
node is 4 
__________
node is 4 
node is 3 
node is 2 
node is 1 
node is 0 
```


### 有序数组合并 （归并算法）
有两个数组：一个为`{1, 2, 5, 6, 7, 8, 9, 19, 20}`，另一个为`{2, 3, 4, 6, 8, 10, 11, 18, 21, 29}`，他们都是有序的，我们需要对这两个数组进行合并，合并后这一个数组依旧是有序的。

- 分析：
定义两个指针p1和p2，p1指针指向第一个数组的首地址，p2指针指向第二个数组的首地址，并使用一个循环，比较这两个指针指向的数据大小，创建一个新的数组，作为合并后的数组，p1和p2指向的内容进行比较，谁的值小就放到新的数组中，然后向前移动指向内容小的那个指针，依次进行比较，遍历结束的条件为p1指针和p2指针不能相对各自的数组越界。

实现：

```c

// 使用归并算法，将有序数组a和b的值合并到一个数组result中，且依旧保持有序
void mergeList(int arr1[], int len1, int arr2[], int len2, int result[]) {
    int *p1 = arr1; // 遍历数组a的指针
    int *p2 = arr2; // 遍历数组b的指针
    int i = 0; // 记录当前存储的位置
    
    while (i < (len1 + len2)) {
        
        // p1 指针已经超出arr1数组的长度，并且p2指针还未超出arr2数组的长度，则将arr2数组中剩余的所有元素添加到result中
        if (p1 >= arr1 + len1 && p2 < arr2 + len2) {
            result[i] = *p2;
            p2++;
        }
        // p2 指针已经超出arr2数组的长度，并且p1指针还未超出arr1数组的长度，则将arr1数组中剩余的所有元素添加到result中
        else if (p2 >= arr2 + len2 && p1 < arr1 + len1) {
            result[i] = *p1;
            p1++;
        }
        else {
            // p1和m2指向的内容进行比较，谁的值小就放到新的数组中，然后向前移动指向内容小的那个指针，依次进行比较
            if (*p1 < *p2) {
                result[i] = *p1;
                p1++;
            }
            else {
                result[i] = *p2;
                p2++;
            }
        }
        
        i++;
    }
}

```

- 测试：

```c
void testMeargeList(void) {
    int a[9] = {1, 2, 5, 6, 7, 8, 9, 19, 20};
    int b[10] = {2, 3, 4, 6, 8, 10, 11, 18, 21, 29};
    int result[19];
    mergeList(a, 9, b, 10, result);
    for (int i = 0; i < 19; i++) {
        printf("i = %d\n", result[i]);
    }
}
```

输出结果
```
i = 1
i = 2
i = 2
i = 3
i = 4
i = 5
i = 6
i = 6
i = 7
i = 8
i = 8
i = 9
i = 10
i = 11
i = 18
i = 19
i = 20
i = 21
i = 29
```

### hash算法
在一个字符串中，找到第一个只出现一次的字符，比如：这个`abddehba`字符串，`e`就是只出现一次的字符。

- 分析：
字符（`char`）是一个长度为8的数据类型，对应的`ASCII`码值一共有256种可能，每个字符根据其ASCII码值作为数组的下标对应数组的一个数字，这样就建立了它本身与存储位置的映射关系，数组中存储的是每个字符出现的次数，然后再遍历数组中哪个字符出现的次数为1，这样就可以找到只出现一次的字符，这就是利用hash算法的原理解决此问题的思路。
首先创建一个数组，用来存储每个字符出现的字数，然后遍历这个表，直到找到首次出现一次的字符串，然后结束循环。

关于哈希表的大小：因为ASCII表的为0-255，因此数组的长度为256（arrayHash[256]）。
关于hash表中字母对应的下标，比如一个字母为`b`，那么它对应的`ASCII`值为`97`，因此它在`arrayHash`中的下标就是为`97`。最终存储在`arrayHash`中b出现的次数，就是下标为`97`的值。
这里面运用到的就是hash算法中很重要的概念：hash函数`f(key)`，也就是说建立了一个字符到它所存储在`arrayHash`中下标的映射关系。存储和查找都通过此函数，有效提高查找效率。
![截屏2019-07-22下午10.36.36.png](https://static.kuwe.top/2019/7/5x5e83B0szBdjwiWH0pZkEft9QaYxETXbiNX586cvfBHVjNIfttLPMvriBS2l5td "截屏2019-07-22下午10.36.36.png")


- 实现：

```c
// 查找一个字符串中首次只出现一次的字符
char findFirstChar(char *src) {
    
    // 定义一个数组hashArray，用来存储各个字母出现次数，
    // 关于数组长度：因为ASCII表的为0-255，因此数组的长度为256（arrayHash[256]）
    int hashArray[256];
    // 对数组的每一个元素进行初始化为0
    memset(hashArray, 0, sizeof(int)*256);
    
    // 定义指针ptr指向源字符串的起始位置
    char *ptr = src;
    
    while (*ptr != '\0') {
        // 将源字符串中出现在hashArray中的字符次数加1
        hashArray[*ptr]++;
        // 移动指针
        ptr++;
    }
    
    char result = '\0';
    
    // 重新将ptr移动到源字符串的首地址
    ptr = src;
    // 遍历每个字符串出现的次数
    while (*ptr != '\0') {
        // 遇到第一个出现次数为1的字符，退出循环
        if (hashArray[*ptr] == 1) {
            result = *ptr;
            break;
        }
        ptr++;
    }
    return  result;
}

```

- 测试：

```c
void testFindFirstChar(void) {
    char *src = "abddehba";
    char firstChar = findFirstChar(src);
    printf("这个字符串:%s中，首次出现的字符为：%c\n", src, firstChar);
}
```

输出结果：
```
这个字符串:abddehba中，首次出现的字符为：e
```
