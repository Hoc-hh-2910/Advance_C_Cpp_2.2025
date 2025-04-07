#ifndef Binary_Search_Tree_H
#define Binary_Search_Tree_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @struct  Node
 * @brief   Cấu trúc của một node trong danh sách liên kết đơn.
 */
typedef struct Node
{
    int data;          /**< Giá trị của node */
    struct Node *next; /**< Con trỏ đến node tiếp theo */
} Node;

 /**
  * @struct  CenterPoint
  * @brief   Cấu trúc của một node trong cây nhị phân tìm kiếm.
  */
 typedef struct CenterPoint
 {
     int value;                  /**< Giá trị của node */
     struct CenterPoint *left;   /**< Con trỏ đến node con trái */
     struct CenterPoint *right;  /**< Con trỏ đến node con phải */
 } CenterPoint;
 
 /**
  * @brief   Thêm node vào danh sách liên kết và sắp xếp theo thứ tự tăng dần.
  * @param   head   Con trỏ đến con trỏ head của danh sách liên kết.
  * @param   value  Giá trị cần thêm vào danh sách.
  * @return  void
  */
void add_node(Node **head, int value);

 /**
  * @brief   Xây dựng cây nhị phân từ danh sách liên kết.
  * @details Tìm điểm giữa danh sách và chia danh sách thành cây nhị phân tìm kiếm.
  * @param   head   Con trỏ đến danh sách liên kết.
  * @param   start  Vị trí bắt đầu của danh sách.
  * @param   end    Vị trí kết thúc của danh sách.
  * @return  CenterPoint*   Gốc của cây nhị phân tìm kiếm.
  */
CenterPoint *buildTree(Node *head, int start, int end);

 /**
  * @brief   Chuyển danh sách liên kết thành cây nhị phân tìm kiếm (BST).
  * @details Tính độ dài danh sách liên kết và gọi `buildTree()` để xây dựng BST.
  * @param   head  Con trỏ đến danh sách liên kết.
  * @return  CenterPoint*  Gốc của cây nhị phân tìm kiếm.
  */
 CenterPoint *centerPoint(Node *head);

 /**
  * @brief   Thực hiện tìm kiếm nhị phân trên cây BST.
  * @details Duyệt cây nhị phân để tìm kiếm giá trị cần tìm.
  * @param   root   Gốc của cây nhị phân.
  * @param   value  Giá trị cần tìm.
  * @return  CenterPoint*   Trả về con trỏ đến node tìm thấy, NULL nếu không tìm thấy.
  */
 CenterPoint *binarySearch(CenterPoint *root, int value);

 /**
  * @brief   In danh sách liên kết.
  * @details Duyệt danh sách liên kết và in ra từng phần tử.
  * @param   head  Con trỏ đến danh sách liên kết.
  * @return  void
  */
 void print_list(Node *head);

 
#endif