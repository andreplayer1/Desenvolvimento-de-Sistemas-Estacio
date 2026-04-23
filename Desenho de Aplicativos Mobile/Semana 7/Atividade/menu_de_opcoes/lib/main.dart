import 'package:flutter/material.dart';
import 'views/menu_principal.dart';

void main() {
  runApp(const MeuApp());
}

class MeuApp extends StatelessWidget {
  const MeuApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'App Estácio - Navegação',
      theme: ThemeData(primarySwatch: Colors.blue),
      home: const MenuPrincipal(),
    );
  }
}