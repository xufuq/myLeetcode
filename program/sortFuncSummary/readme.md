# 冒泡排序

每次比较相邻的两个元素，然后把最大的放到最右边，这样理论上n趟就可以排序完完成

由于在遇到相邻的相等元素时不交换，所以是**稳定排序算法**

# 选择排序

每次从未排序部分选出最小的元素，然后把最小的元素与未排序部分的第一个元素进行交换，逐渐有序

由于最小元素的位置不定，且与最小元素直接交换位置（预知对比，冒泡排序在两个元素相等时不会相互狡猾，所以相对位置不会改变），所以是**不稳定排序算法**。

# 插入排序

是一种比较简单直观的算法，适用数据量比较少或者部分有序的数据。

在部分有序的基础上，看当前需要排序的第一个元素在有序序列中的位置，然后整体后移为当前元素空出一个位置放进去。

是稳定排序算法，因为没有无规律的交换。

因为需要一直移动后半部分的数据，对于大规模数据而言很耗时。

# 希尔排序

插入排序的改进版

**希尔排序的精髓就是通过不同的增量让序列的有序性提高，从而在增量为1时能够尽量减少数据的移动次数**。

通过增量对数据进行分组，一开始的增量设置为数组长度的一般，然后每一个循环都递减

# 递归排序

递归排序是建立在归并操作的一种高效的排序方法，采用了分治的思想，适合处理较大规模的数据，但是比较耗费内存。

**这里看书上关于归并排序的优化**（数据结构与算法）

一直二分拆分，拆到最后只有一组只有一个元素，就自然而然的有序了，然后在合并。

具有稳定性，因为没有索引突变

# 归并排序

时间复杂度为nlgn, 稳定排序算法。

# 快速排序

基于分治的思想和地柜的方式处理子问题。通过一个主元，把一个大的数组分割为两个小部分。

# 最后总结稳定性、时间复杂度
