import 'package:flutter/material.dart';
import 'pages/home_page.dart';

void main() {
  runApp(const MyApp()); // Ponto de entrada do aplicativo
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Easy List', // Nome do app
      theme: ThemeData(
        scaffoldBackgroundColor: const Color(0xFFF4E8D1),

        colorScheme: const ColorScheme.light(
          primary: Color(0xFF8B5A2B),
          surface: Color(0xFFFFF8DC),
          onSurface: Color(0xFF3E2723),
        ),

        appBarTheme: const AppBarTheme(
          backgroundColor: Color(0xFF8B5A2B),
          foregroundColor: Color(0xFFFFF8DC),
          centerTitle: true,
        ),

        floatingActionButtonTheme: const FloatingActionButtonThemeData(
          backgroundColor: Color(0xFF8B5A2B),
          foregroundColor: Color(0xFFFFF8DC),
        ),

        visualDensity: VisualDensity.adaptivePlatformDensity,
        // Responsividade: adapta densidade visual para diferentes dispositivos
      ),
      home: const HomePage(), // Tela inicial
    );
  }
}
