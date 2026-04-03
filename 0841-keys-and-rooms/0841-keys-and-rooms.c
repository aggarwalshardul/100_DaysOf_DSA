void dfs(int room, int** rooms, int* roomsColSize, int* visited) {
    visited[room] = 1;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int nextRoom = rooms[room][i];

        if (!visited[nextRoom]) {
            dfs(nextRoom, rooms, roomsColSize, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int visited[roomsSize];

    // initialize visited
    for (int i = 0; i < roomsSize; i++) {
        visited[i] = 0;
    }

    // start from room 0
    dfs(0, rooms, roomsColSize, visited);

    // check if all visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}