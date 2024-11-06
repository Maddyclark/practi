#!/bin/bash

createaddressbook() {
    echo
    if [ -e addressbook.txt ]; then
        echo "Address book already exists."
    else
        touch addressbook.txt
        echo "Address book created."
    fi
}

insertrecord() {
    while true; do
        echo -e "\nEnter record in the format: lastname,firstname,email,mobile"
        echo -e "Example: Doe,John,johndoe@example.com,1234567890"
        echo -e "To quit, type 'q'"
        
        read -p "Enter record: " newrecord
        if [ "$newrecord" == 'q' ]; then
            break
        fi
        
        echo "$newrecord" >> addressbook.txt
        echo "Record added successfully."
    done
}

viewrecords() {
    if [ -s addressbook.txt ]; then
        cat addressbook.txt
    else
        echo "No records found. The address book is empty."
    fi
}

searchrecord() {
    while true; do
        read -p "Enter keyword to search for (or 'q' to quit): " sayrec
        if [ "$sayrec" == 'q' ]; then
            break
        fi
        
        echo "Searching for \"$sayrec\"..."
        grep "$sayrec" addressbook.txt
        if [ $? -ne 0 ]; then
            echo "No matching record found."
        fi
    done
}

modifyrecord() {
    while true; do
        read -p "Enter keyword to find record to modify (or 'q' to quit): " mrecord
        if [ "$mrecord" == 'q' ]; then
            break
        fi
        
        grep -n "$mrecord" addressbook.txt
        if [ $? -ne 0 ]; then
            echo "No matching record found."
        else
            read -p "Enter the line number to edit: " linenumber
            read -p "Enter the new record (format: lastname,firstname,email,mobile): " erecord
            sed -i "${linenumber}s/.*/$erecord/" addressbook.txt
            echo "Record updated successfully."
        fi
    done
}

deleterecord() {
    while true; do
        read -p "Enter keyword to find record to delete (or 'q' to quit): " drecord
        if [ "$drecord" == 'q' ]; then
            break
        fi
        
        grep -n "$drecord" addressbook.txt
        if [ $? -ne 0 ]; then
            echo "No matching record found."
        else
            read -p "Enter the line number to delete: " linenum
            sed -i "${linenum}d" addressbook.txt
            echo "Record deleted successfully."
        fi
    done
}

echo "Welcome to the Address Book Manager"
createaddressbook

while true; do
    echo -e "\nMain Menu"
    echo "1: Create Address Book"
    echo "2: Insert a Record"
    echo "3: View Records"
    echo "4: Modify a Record"
    echo "5: Delete a Record"
    echo "6: Search a Record"
    echo "7: Exit"
    
    read -p "Choose an option (1-7): " choice
    case $choice in
        1) createaddressbook ;;
        2) insertrecord ;;
        3) viewrecords ;;
        4) modifyrecord ;;
        5) deleterecord ;;
        6) searchrecord ;;
        7) echo "Exiting Address Book Manager. Goodbye!"; exit ;;
        *) echo "Invalid option, please try again." ;;
    esac
done
