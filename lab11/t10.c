#include <stdio.h>

struct TPair {
    unsigned key;
    char data[10];
};

int searchRecordByKey(FILE *file, unsigned targetKey, struct TPair *foundRecord) {
    struct TPair currentRecord;

    rewind(file);

    while (fread(&currentRecord, sizeof(struct TPair), 1, file) == 1) {
        if (currentRecord.key == targetKey) {
            // Знайдено запис
            if (foundRecord != NULL) {
                *foundRecord = currentRecord;
            }
            return 1;
        } else if (currentRecord.key > targetKey) {
            return 0;
        }
    }

    return 0;
}

int deleteRecordByKey(FILE *file, unsigned targetKey) {
    FILE *tempFile = fopen("tempFile.tmp", "wb");
    if (tempFile == NULL) {
        fprintf(stderr, "error opening\n");
        return 0;
    }

    struct TPair currentRecord;

    rewind(file);

    while (fread(&currentRecord, sizeof(struct TPair), 1, file) == 1) {
        if (currentRecord.key != targetKey) {
            fwrite(&currentRecord, sizeof(struct TPair), 1, tempFile);
        }
    }

    // Закриття файлів
    fclose(file);
    fclose(tempFile);

    // Видалення оригінального файлу та перейменування тимчасового на його місце
    remove("originalFile.txt");
    rename("tempFile.tmp", "originalFile.txt");

    return 1;
}

int main() {
    FILE *file = fopen("originalFile.txt", "rb");
    if (file == NULL) {
        fprintf(stderr, "error opening\n");
        return 1;
    }

    unsigned targetKey;
    struct TPair foundRecord;

    // Приклад пошуку запису за ключем
    printf("key: ");
    scanf("%u", &targetKey);

    if (searchRecordByKey(file, targetKey, &foundRecord)) {
        printf("found%u: %s\n", foundRecord.key, foundRecord.data);
    } else {
        printf("string %u not found\n", targetKey);
    }

    printf("key for del: ");
    scanf("%u", &targetKey);

    if (deleteRecordByKey(file, targetKey)) {
        printf("string %u deleted\n", targetKey);
    } else {
        printf("not deleted %u\n", targetKey);
    }

    fclose(file);

    return 0;
}
