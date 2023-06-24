int arr[4] = {1, 2, 3, 4};
int arr1[2][2] = {{1, 2}, {3, 4}};

const int c = 2;

int main() {
    int i = c + 2;
    while (i) {
        i = i + 1;
        if (i == 5) {
            break;
        }
    }
    return i;
}