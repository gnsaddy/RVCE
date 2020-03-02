package com.addy.sendmessage;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    EditText num,msg;
    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        num = findViewById(R.id.editText2);
        msg = findViewById(R.id.editText3);
        btn = findViewById(R.id.button);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                sendSmsByIntent();
            }
        });
    }
    public void sendSmsByIntent(){
        Uri uri =  Uri.parse("smsto:" + num.getText().toString());
        Intent smsIntent = new Intent(Intent.ACTION_SENDTO,uri);
        smsIntent.putExtra("sms_body", msg.getText().toString());
        try {
            startActivity(smsIntent);
        }catch (Exception e){
            Toast.makeText(MainActivity.this,"SMS sending failed ",Toast.LENGTH_LONG).show();
            e.printStackTrace();
        }
    }
}
