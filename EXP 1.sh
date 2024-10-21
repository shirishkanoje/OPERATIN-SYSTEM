

echo "Welcome to my address book..."
read -p "Enter the address book name: " bname

if [ ! -e $bname ]; then
    touch $bname
    echo "Address book with the name $bname created successfully"
    echo -e "ID\t\tNAME\t\tMOBILE\t\tEMAIL" >> $bname
else 
    echo "Address book already exists !!!"
fi
while true; do
    echo ""
    echo "**************Address Book**************"
    echo "a. Display Address book"
    echo "b. Insert a record"
    echo "c. Delete a record"
    echo "d. Modify a record"
    echo "e. Exit"
    read ch

    case $ch in
    a)
        cat $bname
        echo ""
        ;;
    b)
        read -p "Enter ID: " id
        read -p "Enter Name: " name
        read -p "Enter Mobile: " mobile
        read -p "Enter Email: " email
        echo -e "$id\t\t$name\t\t$mobile\t\t$email" >>$bname
        ;;
    c)
        read -p "Enter the ID to be deleted: " did
        if grep -qw $did $bname; then
            grep -vw $did $bname >> temp
            mv temp $bname
        echo "Record deletion success..."
        else
            echo "Record  with $did does not exists"
        fi
        ;;
    d)
        read -p "Enter the ID to be modified: " mid
        if grep -qw $mid $bname; then
            grep -vw $mid $bname >> temp
            mv temp $bname

            read -p "Enter ID: " id
            read -p "Enter Name: " name
            read -p "Enter Mobile: " mobile
            read -p "Enter Email: " email
            echo -e "$id\t\t$name\t$mobile\t$email" >>$bname
            echo "Record Modified successfully..."
        else
            echo "Record  with $did does not exists"
        fi
        ;;
    e)
        echo "Thank you!"
        exit
        ;;
    *)
        echo "Please enter the correct choice"
    esac
done
