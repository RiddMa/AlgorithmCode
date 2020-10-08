/*
 * Created by 马嘉骥 on 2020/10/4.
 * 思路：对于快速选择算法，一个可行的思路是在n很小时，用一个高效的简单排序算法对数组进行排序并选择第k元素，
 * 在n较大时，参考快速排序的pivot思想，将数组均分为k组，每组中随机取一个元素，并对这k个元素进行排序，选择中间值元素，
 * 首先使用partition将数组分区，以该元素作为pivot，将所有元素与该元素比较，小于该元素的放pivot左边，大于该元素的放右边。
 * 分区完成后，将pivot元素的index与k比较，并根据大小访问其中一边的分区，再递归地对该分区选择pivot并进行分区。
 */

#include "QuickSelect.h"

long long RandomizedPartition(long long left, long long right)
{
    default_random_engine e;
    uniform_int_distribution<long long> u(left, right);
    e.seed(time(nullptr));
    long long pi = u(e);
    return rand()%(right-left)+left;
}

/*
 * 快速选择算法，与快速排序类似，但每次抛弃pivot的一侧元素
 */
template<class Type>
Type QuickSelect(Type Source[], long long left, long long right, long long k)
{
    if(left==right)return Source[left];
    long long x = RandomizedPartition(left, right);

}