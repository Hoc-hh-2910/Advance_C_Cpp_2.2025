# Pthread

Thư viện ``pthread`` (POSIX Threads) là một phần quan trọng trong lập trình đa luồng (multithreading) trên hệ điều hành Unix/Linux. Nó cho phép bạn tạo và quản lý nhiều luồng (threads) trong một tiến trình (process), giúp tận dụng hiệu quả tài nguyên CPU, đặc biệt khi bạn cần thực hiện các tác vụ song song.

Cung cấp các hàm để:
- Tạo và hủy thread
- Đồng bộ hóa (mutex, condition variables)
- Điều khiển luồng (join, detach, ...)

Một số hàm phổ biến trong ``pthread``

- ``pthread_create()``: tạo thread mới
- ``pthread_join()``: Chờ thread kết thúc
- ``pthread_exit()``: Kết thúc một thread
- ``pthread_detach()``: Cho phép thread tự giải phóng tài nguyên khi kết thúc
- ``pthread_mutex_*``: Đồng bộ bằng mutex
- ``pthread_cond_*``: Sử dụng condition variables để đồng bộ nâng cao hơn

Khi nào nên dùng ``pthread``:

- Khi cần thực hiện tác vụ nặng song song (xử lý ảnh, AI, tính toán, ...)
- Khi cần viết server nhiều client (mỗi client là một thread)
- Khi muốn tận dụng đa nhân CPU

