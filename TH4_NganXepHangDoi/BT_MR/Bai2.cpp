#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int MAX_N = 100; // Giới hạn kích thước mê cung
int maze[MAX_N][MAX_N]; // Mê cung
bool visited[MAX_N][MAX_N]; // Đánh dấu ô đã đi qua
pair<int, int> parent[MAX_N][MAX_N]; // Lưu đường đi

// Hướng di chuyển: trái, phải, lên, xuống
int dx[] = {0, 0, -1, 1}; // Dịch chuyển hàng
int dy[] = {-1, 1, 0, 0}; // Dịch chuyển cột

struct Cell {
    int x, y; // Tọa độ ô
};

// Hàm kiểm tra một ô có hợp lệ để di chuyển không
bool isValid(int x, int y, int N, int M) {
    return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 0 && !visited[x][y]);
}

void bfs(int N, int M, int x0, int y0, int x1, int y1) {
    queue<Cell> q; // Hàng đợi BFS
    q.push({x0, y0}); // Đưa điểm xuất phát vào hàng đợi
    visited[x0][y0] = true;
    parent[x0][y0] = {-1, -1};
    
    while (!q.empty()) {
        Cell curr = q.front(); q.pop();
        
        // Nếu đến điểm đích, thoát vòng lặp
        if (curr.x == x1 && curr.y == y1) break;
        
        // Duyệt 4 hướng di chuyển
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            
            if (isValid(nx, ny, N, M)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {curr.x, curr.y}; // Lưu ô trước đó để truy vết đường đi
                q.push({nx, ny});
            }
        }
    }
    
    // Kiểm tra có đến đích được không
    if (!visited[x1][y1]) {
        cout << "0" << endl; // Không có đường đi
        return;
    }
    
    // Truy vết ngược để tìm đường đi từ (x1, y1) về (x0, y0)
    stack<Cell> path;
    for (Cell at = {x1, y1}; at.x != -1; at = {parent[at.x][at.y].first, parent[at.x][at.y].second}) {
        path.push(at);
    }
    
    // In số ô trong đường đi
    cout << path.size() << endl;
    
    // In đường đi theo thứ tự từ (x0, y0) đến (x1, y1)
    while (!path.empty()) {
        Cell p = path.top(); path.pop();
        cout << p.x + 1 << " " << p.y + 1 << endl; // Đổi về chỉ số 1-based
    }
}

int main() {
    int N, M, x0, y0, x1, y1;
    cin >> N >> M >> x0 >> y0 >> x1 >> y1;
    x0--; y0--; x1--; y1--; // Chuyển về chỉ số 0-based
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
            visited[i][j] = false;
        }
    }
    
    bfs(N, M, x0, y0, x1, y1);
    return 0;
}