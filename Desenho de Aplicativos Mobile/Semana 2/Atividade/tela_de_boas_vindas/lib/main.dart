import 'package:flutter/material.dart';

// O botão "Power" do aplicativo
void main() {
  runApp(const MeuApp());
}

// A estrutura principal do App
class MeuApp extends StatelessWidget {
  const MeuApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false, // Tira aquela faixa de "Debug" do canto
      home: Scaffold(
        body: Container(
          margin: const EdgeInsets.all(20.0), // Margem ao redor do conteúdo
          width: double.infinity, // Faz o container ocupar toda a largura

          decoration: BoxDecoration(
            color: Colors.blue, // Cor de fundo do container
            borderRadius: BorderRadius.circular(20), // Bordas arredondadas
            border: Border.all(
              color: Colors.blueGrey, // Cor da borda
              width: 2, // Largura da borda
            ),
            boxShadow: const [
              BoxShadow(
                color: Colors.black26, // Cor da sombra
                blurRadius: 8, // Desfoque da sombra
                offset: Offset(5, 5), // Deslocamento da sombra
              )
            ]
          ),

          child: Column(
            mainAxisAlignment: MainAxisAlignment.center, // Centraliza verticalmente
            children: [
              Text(
                'Bem Vindo Ao Meu App!',
                style: TextStyle(
                  fontSize: 28,
                  fontWeight: FontWeight.bold,
                  color: Colors.white,
                )
                ),

                const SizedBox(height: 30,),
                Image.network(
                  'https://cdn-icons-png.flaticon.com/512/3003/3003285.png', height: 150,
                )
              
            ],
          )
        )
      ),
    );
  }
}