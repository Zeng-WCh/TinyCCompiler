int arr[4] = {0, 0, 3, 4};

int main() {
    if (arr[1]) {
        return 1;
    }
    else {
        arr[1] = 113;
    }
    return arr[1] + arr[2];
}