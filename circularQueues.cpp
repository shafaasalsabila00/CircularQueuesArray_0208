/**
 * @mainpage Documentation circularQueues
 * 
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section Operations
 * - en queues for insert element into queues
 * - de queues for delete element from queues
 * - show data / display
 * 
 * @section How to use
 * 1. Insert 
 * 2. Delete
 * 3. Display
 * 4. Exit
 * 
 * @author yProfil
 * - Nama : Shafa Salsabila Ramadhani
 * - NIM : 20240140208
 * - Kelas : E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief This class is for operation queues
 * 
 */
class Queues 
{
private: 
    static const int max = 5; 
    int FRONT; /// private variable front for indicate first element
    int REAR; /// private variable rear for indicate the last element
    int max = 5; /// private variable max for capasity for element
    int queue_array[5]; /// private variable queue_array to store elements

public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues() { 
        FRONT = -1;  
        REAR = -1;
    }

    /**
     * @brief method for entering data into a queues
     * Meminta pengguna untuk memasukkan bilangan bulat dan memasukkannya ke dalam antrean jika belum penuh.
     * Menampilkan pesan jika antrean penuh (overflow).
     */
    void insert() {  
        int num;  /// variable untuk menyimpan nilai bilangan bulat
        cout << "Enter a number: ";
        cin >> num; 
        cout << endl;

        
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n"; 
            return; 
        }

        
        if (FRONT == -1) {
            FRONT = 0; 
            REAR = 0; 
        }
        else { 
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }


    /**
     * @brief method untuk memastikan queues tidak kosong sebelum menghapusnya
     * 
     */
    void remove() {
        if (FRONT == -1) {
            cout << "Queue underflow\n"; 
            return; 
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";


        if (FRONT == REAR) { 
            FRONT = -1;
            REAR = -1;
        }
        else { 
            if (FRONT == max -1) 
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    /**
     * @brief Menampilkan semua elemen dalam antrian.
     * 
     */
    void display() {
        int FRONT_position = FRONT; ///variable front_potition untuk menyimpan nilai pada variable front digunakan dalam antrian tanpa mengubah nlai awal
        int REAR_position = REAR; ///variable rear_potition untuk menyimpan nilai pada variable rear digunakan dalam antrian tanpa mengubah nlai awal

        if (FRONT == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            while (FRONT_position <= max - 1) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }

            FRONT_position = 0;
            
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

/**
 * @brief method untuk memanggil fungsi insert, remove, dan display pada fungsi utama
 * 
 * @return int 
 */
int main()
{
    Queues q; /// membuat objek dari class Queues
    char ch; /// veriable untuk menampung pilihan menu

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }    
    }
}