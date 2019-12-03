from django import forms
from src.models import Emp


class CreateEmp(forms.ModelForm):
    class Meta:
        model = Emp
        fields = '__all__'
