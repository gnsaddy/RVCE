package com.addy.myrecorder;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.content.pm.PackageManager;
import android.media.MediaPlayer;
import android.media.MediaRecorder;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.widget.ImageButton;
import android.widget.Toast;

import java.io.IOException;

import static android.Manifest.permission.RECORD_AUDIO;
import static android.Manifest.permission.WRITE_EXTERNAL_STORAGE;

public class MainActivity extends AppCompatActivity {

    ImageButton brecord,bstop,bplay,bstopplay,bpause;
    MediaRecorder mRecorder;
    MediaPlayer mPlayer;

    private final static String LOG_TAG = "AudioRecord";
    static String mfileName = null;
    public final static int RECORD_AUDIO_PERMISSION_CODE = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        brecord = findViewById(R.id.btnrecord);
        bstop = findViewById(R.id.btnstop);
        bplay = findViewById(R.id.btnplay);
        bstopplay = findViewById(R.id.btnstopplay);
        bpause = findViewById(R.id.btnpause);

        mPlayer = new MediaPlayer();
        mRecorder = new MediaRecorder();

        bstop.setEnabled(false);
        bplay.setEnabled(false);
        bpause.setEnabled(false);
        bstopplay.setEnabled(false);

        mfileName = Environment.getExternalStorageDirectory().getAbsolutePath();
        mfileName += "/audio.3gp";

        brecord.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if (CheckPermission()) {
                    brecord.setEnabled(false);
                    bstop.setEnabled(true);
                    bplay.setEnabled(false);
                    bpause.setEnabled(false);
                    bstopplay.setEnabled(false);

                    mRecorder = new MediaRecorder();
                    mRecorder.setAudioSource(MediaRecorder.AudioSource.MIC);
                    mRecorder.setOutputFormat(MediaRecorder.OutputFormat.THREE_GPP);
                    mRecorder.setAudioEncoder(MediaRecorder.AudioEncoder.AMR_NB);
                    mRecorder.setOutputFile(mfileName);
                    try {
                        mRecorder.prepare();
                    } catch (IOException e) {
                        Log.e(LOG_TAG, "prepare() failed");
                    }
                    mRecorder.start();
                    Toast.makeText(getApplicationContext(),"Recording started ",Toast.LENGTH_LONG).show();
                }else {
                    RequestPermission();
                }
            }
        });

        bstop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                brecord.setEnabled(true);
                bstop.setEnabled(false);
                bplay.setEnabled(true);
                bpause.setEnabled(false);
                bstopplay.setEnabled(false);

                mRecorder.stop();;
                mRecorder.release();

                Toast.makeText(getApplicationContext(),"Recording stop ",Toast.LENGTH_LONG).show();
            }
        });

        bplay.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                brecord.setEnabled(true);
                bstop.setEnabled(false);
                bplay.setEnabled(false);
                bpause.setEnabled(true);
                bstopplay.setEnabled(true);

                mPlayer = new MediaPlayer();
                try{
                    mPlayer.setDataSource(mfileName);
                    mPlayer.prepare();
                    mPlayer.start();
                } catch (IOException e) {
                    Log.e(LOG_TAG,"prepare() failed");
                }

                Toast.makeText(getApplicationContext(),"play Recording  ",Toast.LENGTH_LONG).show();
            }
        });

        bpause.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(mPlayer.isPlaying())
                    mPlayer.pause();
                else
                    mPlayer.start();
                brecord.setEnabled(false);
                bstop.setEnabled(false);
                bplay.setEnabled(false);
                bpause.setEnabled(true);
                bstopplay.setEnabled(true);


                Toast.makeText(getApplicationContext(),"playing pause  ",Toast.LENGTH_LONG).show();

            }
        });



        bstopplay.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mPlayer.release();
                mfileName = null;
                brecord.setEnabled(true);
                bstop.setEnabled(false);
                bplay.setEnabled(false);
                bpause.setEnabled(false);
                bstopplay.setEnabled(false);

                Toast.makeText(getApplicationContext(),"playing stop ",Toast.LENGTH_LONG).show();

            }
        });

    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        switch (requestCode){
            case RECORD_AUDIO_PERMISSION_CODE:
                if(grantResults.length>0){
                    boolean permissionToRecord = grantResults[0] == PackageManager.PERMISSION_GRANTED;
                    boolean permissionToStore = grantResults[1] == PackageManager.PERMISSION_GRANTED;

                    if(permissionToRecord && permissionToStore){
                        Toast.makeText(getApplicationContext(),"Permission granted ",Toast.LENGTH_LONG).show();
                    }else {
                        Toast.makeText(getApplicationContext(),"Permission denied ",Toast.LENGTH_LONG).show();
                    }
                }
                break;
        }
    }

    public boolean CheckPermission(){
        int res = ContextCompat.checkSelfPermission(getApplicationContext(),WRITE_EXTERNAL_STORAGE);
        int res1 = ContextCompat.checkSelfPermission(getApplicationContext(),RECORD_AUDIO);

        return res == PackageManager.PERMISSION_GRANTED && res1 == PackageManager.PERMISSION_GRANTED;
    }

    private void RequestPermission(){
        ActivityCompat.requestPermissions(MainActivity.this,new String[] {RECORD_AUDIO,WRITE_EXTERNAL_STORAGE},
                RECORD_AUDIO_PERMISSION_CODE);
    }
}
