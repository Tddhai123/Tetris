---------------------------------------------------------TETRIS---------------------------------------------------------

1: Hướng dẫn cài đặt(cho Windows)

  B1: Tải CodeBlocks bản codeblocks-20.03mingw-setup.exe ở link http://www.codeblocks.org/downloads/binaries/
  
  B2: Tải code về rồi giải nén, sau đó chạy file Tetris.cbp
  
  B3: Sau khi mở được project trên CodeBlocks thì vào Build -> Build and run (hoặc ấn F9) để có thể chạy chương trình
  
  Các file SDL2 đã được để sẵn trong folder SDL2 nên không cần tải về nữa

2: Mô tả chung về trò chơi
  - Tương tự như game Tetris cổ điển
  - Ta sẽ xếp các khối sao cho thành hàng ngang hoàn chỉnh để có thể bỏ được hàng đó đi
  - Được càng nhiểu điểm thì tốc độ rơi càng nhanh

3: Mô tả các chức năng đã cài đặt
  - Dùng các phím mũi tên để di chuyển (phím lên và phím X để quay các khối)
  - Phím Space để cho các khối xuống luôn mà không cần chờ 
  - Phím C để đổi khối hiện tại với khối đang được giữ (Nếu chưa có khối nào được giữ thì đưa khối hiện tại lên chỗ giữ khối và đổi với khối tiếp theo)
  - Phím Enter để lựa chọn
  - Phím P để pause
  - Phím Escape để quay lại
  - Trong phần Options thì có đổi kích thước màn hình và tắt/bật ghost block
  - Link video demo chức năng: 

4: Các kĩ thuật lập trình được sử dụng trong chương trình
  - Đồ họa SDL, SDL_image, SDL_ttf
  - Mảng, swap, con trỏ
  - Class, vòng lặp
  - Vector, load ảnh từ file

5: Kết luận
  - Các hàm cơ bản của đối tượng được tham khảo từ phattrienphanmem123
  - Các hàm nâng cao hơn về game học từ lazyfoo
  - Hướng phát triển
    + Có thể chơi 2 người thi xem ai nhiều điểm và lâu thua hơn
  - Các điều tâm đắc rút ra được sau khi hoàn thiện chương trình
    + Dùng Class một cách hợp lý
    + Tách file
    + Code sạch, refactor
