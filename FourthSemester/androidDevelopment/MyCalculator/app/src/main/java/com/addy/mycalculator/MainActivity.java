package com.addy.mycalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.InputType;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    EditText et1,et2,res;
    Button btn1,btn2,btn3,btn4,btn5;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        et1 = findViewById(R.id.editText1);
        et2 = findViewById(R.id.editText2);
        btn1 = findViewById(R.id.buttonplus);
        btn2 = findViewById(R.id.buttonminus);
        btn3 = findViewById(R.id.buttonmult);
        btn4 = findViewById(R.id.buttondiv);
        btn5 = findViewById(R.id.buttonclr);
        res = findViewById(R.id.res);

        et1.setInputType(InputType.TYPE_CLASS_NUMBER);
        et2.setInputType(InputType.TYPE_CLASS_NUMBER);

        btn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(et1.getText().length() > 0  && et2.getText().length()>0){
                    double etone = Double.parseDouble(et1.getText().toString());
                    double etwo = Double.parseDouble(et2.getText().toString());

                    double result = etone + etwo;
                    res.setText(Double.toString(result));
                }
                else{
                    Toast.makeText(MainActivity.this,"Invalid value of x,y",Toast.LENGTH_LONG).show();
                }
            }
        });

        btn2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(et1.getText().length() > 0  && et2.getText().length()>0){
                    double etone = Double.parseDouble(et1.getText().toString());
                    double etwo = Double.parseDouble(et2.getText().toString());

                    double result = etone - etwo;
                    res.setText(Double.toString(result));
                }
            }
        });

        btn3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(et1.getText().length() > 0  && et2.getText().length()>0){
                    double etone = Double.parseDouble(et1.getText().toString());
                    double etwo = Double.parseDouble(et2.getText().toString());

                    double result = etone * etwo;
                    res.setText(Double.toString(result));
                }
            }
        });

        btn4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(et1.getText().length() > 0  && et2.getText().length()>0){
                    double etone = Double.parseDouble(et1.getText().toString());
                    double etwo = Double.parseDouble(et2.getText().toString());

                    double result = etone / etwo;
                    res.setText(Double.toString(result));
                }
            }
        });
        btn5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(et1.getText().length() > 0  && et2.getText().length()>0){
                    double etone = Double.parseDouble(et1.getText().toString());
                    double etwo = Double.parseDouble(et2.getText().toString());

                    String result = "";
                    res.setText(result);
                    et1.setText(result);
                    et2.setText(result);
                    et1.requestFocus();
                }
            }
        });
    }
}
