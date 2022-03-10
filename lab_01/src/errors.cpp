#include "errors.h"

void log_error(int err)
{
    switch (err)
    {
        case FILE_NOT_EXIST:
            QMessageBox::critical(NULL, "Ошибка", "При открытии файла произошла ошибка.");
            break;
        case ALLOC_ERROR:
            QMessageBox::critical(NULL, "Ошибка", "При выделении памяти произошла ошибка.");
            break;
        case INCORRECT_DATA:
            QMessageBox::critical(NULL, "Ошибка", "Неверные входные данные.");
            break;
        case INPUT_ERROR:
            QMessageBox::critical(NULL, "Ошибка", "Ошибка ввода.");
            break;
        case INSUFFICIENT_POINTS:
            QMessageBox::critical(NULL, "Ошибка", "Некорретный размер количества точек.");
            break;
        case INSUFFICIENT_LINKS:
            QMessageBox::critical(NULL, "Ошибка", "Некорректный размер количества линий.");
            break;
        case SMALL_SCALE_ERROR:
            QMessageBox::critical(NULL, "Ошибка", "Некорректные параметры масштабирования.");
            break;
        case EMPTY_DATA:
            QMessageBox::critical(NULL, "Ошибка", "Пустые данные.");
            break;
        case FIGURE_NOT_CREATED:
            QMessageBox::critical(NULL, "Ошибка", "Пустая фигура.");
            break;
        case UNKNOWN_COMMAND:
            QMessageBox::critical(NULL, "Ошибка", "Неизвестная команда.");
            break;
        case NO_BACKUP:
            QMessageBox::critical(NULL, "Ошибка", "Файл сброса не найден.");
            break;
        case EDGES_EXCEED_POINTS:
            QMessageBox::critical(NULL, "Ошибка", "Значения краев модели не совпадают с точками.");
            break;
        default:
            QMessageBox::critical(NULL, "Ошибка", "Неизвестная ошибка.");
    }
}