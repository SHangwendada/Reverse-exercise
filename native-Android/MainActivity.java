package com.example.cppandriod;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.example.cppandriod.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'cppandriod' library on application startup.
    static {
        System.loadLibrary("cppandriod");
    }
    public int clickcont = 0;
    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        //TextView tv = binding.sampleText;
        //tv.setText(stringFromJNI());
    }
    public void click(View a){
        clickcont ++;
        TextView tv = binding.sampleText;
        if(clickcont>=1000000){
            tv.setText(stringFromJNI());
            Toast.makeText(this, "不错嘛小伙子", Toast.LENGTH_SHORT).show();
        }else{
            tv.setText("你已经点击了"+clickcont+"次");
            Toast.makeText(this, "加油小伙子", Toast.LENGTH_SHORT).show();
        }
    }
    /**
     * A native method that is implemented by the 'cppandriod' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}