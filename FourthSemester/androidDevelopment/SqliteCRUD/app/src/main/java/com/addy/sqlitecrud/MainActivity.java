package com.addy.sqlitecrud;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    DatabaseHelperClass databaseHelperClass;
    EditText usn,name,cgpa;
    Button createTbl,addData,updateData,deleteData,viewData;
    ImageButton emailData,clearField;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        databaseHelperClass = new DatabaseHelperClass(this);
        usn = findViewById(R.id.editUsn);
        name = findViewById(R.id.editName);
        cgpa = findViewById(R.id.editCgpa);

        createTbl = findViewById(R.id.btnCreate);
        addData = findViewById(R.id.btnAdd);
        viewData = findViewById(R.id.btnView);
        updateData = findViewById(R.id.btnUpdate);
        deleteData = findViewById(R.id.btnDelete);
        emailData = findViewById(R.id.btnMail);
        clearField = findViewById(R.id.btnClear);


        AddData();
        UpdateData();
        ViewAll();
        DeleteData();
        SendToMail();
        ClearData();
//        createTable();
    }

    public void AddData(){
        addData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                boolean isInserted = databaseHelperClass.insertData(usn.getText().toString(), name.getText().toString(), cgpa.getText().toString());
                if (isInserted == true) {
                    Toast.makeText(MainActivity.this,"Data Inserted !!!",Toast.LENGTH_LONG).show();
                }else {
                    Toast.makeText(MainActivity.this,"Data not Inserted !!!",Toast.LENGTH_LONG).show();
                }
            }
        });
    }

    public void UpdateData(){
        updateData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                boolean isUpdated = databaseHelperClass.updateDataThroughId(usn.getText().toString(),name.getText().toString(),cgpa.getText().toString());
                if(isUpdated == true){
                    Toast.makeText(MainActivity.this,"Data Updated !!!",Toast.LENGTH_LONG).show();
                }else {
                    Toast.makeText(MainActivity.this,"Data not updated !!!",Toast.LENGTH_LONG).show();
                }
            }
        });
    }

    public void DeleteData(){
        deleteData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Integer deletedRows = databaseHelperClass.deleteDataThroughId(usn.getText().toString());
                if( deletedRows > 0){
                    Toast.makeText(MainActivity.this,"Data deleted !!!",Toast.LENGTH_LONG).show();
                }else {
                    Toast.makeText(MainActivity.this,"Data not deleted !!!",Toast.LENGTH_LONG).show();
                }
            }
        });
    }

    public void ViewAll(){
        viewData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Cursor cursor = databaseHelperClass.getAllData();
                if(cursor.getCount() == 0){
                    showMessage("Error", "No record found ");
                    Toast.makeText(MainActivity.this,"Data not available !!!",Toast.LENGTH_LONG).show();
                    return;
                }else {
                    StringBuffer stringBuffer = new StringBuffer();
                    while (cursor.moveToNext()){
                        stringBuffer.append("\nUSN : " + cursor.getString(0)+"\n");
                        stringBuffer.append("NAME : " + cursor.getString(1)+"\n");
                        stringBuffer.append("CGPA : " + cursor.getString(2)+"\n");
                        stringBuffer.append("\n---------------------------------------\n");
                    }
                    showMessage("DATA : ",stringBuffer.toString());
                }
            }
        });
    }

    public void showMessage(String title, String message){
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setCancelable(true);
        builder.setIcon(R.drawable.test);
        builder.setTitle(title);
        builder.setMessage(message);
        builder.setPositiveButton("ok", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialogInterface, int i) {
                Toast.makeText(getApplicationContext(),"Ok clicked",Toast.LENGTH_LONG).show();
            }
        });
        builder.show();
    }

    public void SendToMail(){
        emailData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String id = usn.getText().toString();
                String nm = name.getText().toString();
                String mark = cgpa.getText().toString();
                Intent intentMail = new Intent(Intent.ACTION_SEND);
                intentMail.putExtra(Intent.EXTRA_EMAIL, new String[]{"gnsaddy@gmail.com"});
                intentMail.putExtra(Intent.EXTRA_SUBJECT, "Testing sending mail");
                intentMail.putExtra(Intent.EXTRA_TEXT,"USN : " + id +"\nNAME : " + nm + "\nCGPA : " + mark);
                intentMail.setType("message/rfc822");
                startActivity(Intent.createChooser(intentMail,"Choose Mail App"));
            }
        });
    }

    public void ClearData(){
        clearField.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                usn.setText("");
                name.setText("");
                cgpa.setText("");
            }
        });
    }
}
